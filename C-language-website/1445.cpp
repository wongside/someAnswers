#include <iostream>
using namespace std;

long long t[505][505];

int main(){
	long long n, m, tmp;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> tmp;
			t[i][j] = tmp + t[i][j-1];
		}
	}
	long long sum = -1000000000;
	for(int ai = 1; ai <= n; ai++){
		for(int aj = 1; aj <= m; aj++){
			for(int bi = ai; bi <= n; bi++){
				for(int bj = bi; bj <= m; bj++){
					tmp = 0;
					for(int k = ai; k <= bi; k++){
						tmp += t[k][bj] - t[k][aj-1];
					}
					if(tmp > sum){
						sum = tmp;
					}
				}
			}
		}
	}
	cout << sum;
	
	return 0;
}
