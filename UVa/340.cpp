#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 1005;

int que[maxn], ans[maxn];
int que_sum[10];
int ans_sum[10];

int main(){
	int n, cnt = 0;
	while((cin >> n) && n){
		memset(que_sum, 0 ,sizeof(int) * 10);
		for(int i = 0; i < n; i++){
			cin >> que[i];
			que_sum[que[i]]++;
		}
		cout << "Game " << ++cnt << ":" << endl;
		while(1){
			int a = 0, b = 0;
			memset(ans_sum, 0 ,sizeof(ans_sum));
			for(int i = 0; i < n; i++){
				cin >> ans[i];
				if(ans[i] == que[i]){
					a++;
				}
				ans_sum[ans[i]]++;
			}
			if(!ans[0]){
				break;
			}	
			for(int i = 1; i < 10; i++){
				b += min(que_sum[i], ans_sum[i]);
			}
			cout << "    (" << a << "," << b-a << ")\n";
		}		
	}
	
	return 0;
}
