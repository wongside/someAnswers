//
// Created by side on 2021/8/31.
//

#include <iostream>
#include <algorithm>
using namespace std;


int heads[20000 + 5];
int knights[20000 + 4];

int main(){

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", heads + i);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", knights + i);
        }

        std::sort(heads, heads + n);
        std::sort(knights, knights + m);

        int p = 0;
        int tol = 0;
        bool ok = true;

        for (int i = 0; i < n; ++i) {
            bool f = false;
            for (int j = p; j < m; ++j) {
                if(heads[i] <= knights[j]) {
                    tol += knights[j];
                    f = true;
                    p = j + 1;
                    break;
                }
            }
            if (!f) {
                printf("Loowater is doomed!\n");
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("%d\n", tol);
        }
    }

    return 0;
}