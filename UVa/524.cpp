#include <iostream>
#include <cstring>
using namespace std;

int prime[100]; // 素数表，prime[0]为素数个数 

/*
Euler筛法获取素数 
*/
void getPrime(){	
	for(int i = 2; i < 100; i++){
		if(prime[i] == 0){
			prime[++prime[0]] = i;
		}
		for(int j = 1; j <= prime[0] && prime[j]*i < 100; j++){
			prime[prime[j]*i] = 1;
			if(i % prime[j] == 0){
				break;
			}
		}
	}
//  打印素数表	
//	for(int i = 1; i <= prime[0]; i++){	
//		cout << prime[i] << endl;
//	}
}

int vis[20];	// 判断数字是否已经使用过 
int ans[20];	// 存储结果 

void dfs(int n){
	
	if(ans[0] == n){
		int t = ans[n] + 1;
		for(int i = 1; i <= prime[0]; i++){
			if(t == prime[i]){ //判断最后一个数和第一个数 
				for(int j = 1; j <= ans[0]; j++){ //打印结果 
					if(j != 1){
						cout << " ";
					}
					cout << ans[j];
				}
				cout << endl;
			}
		}
		return;
	}
	
	for(int i = 1; i <= prime[0]; i++){
		int t = prime[i] - ans[ans[0]];
		if(t > n){
			break;
		}
		if(t < 1){
			continue;
		}
		if(vis[t] == 0){
			vis[t] = 1;
			ans[++ans[0]] = t;
			dfs(n);
			ans[ans[0]--] = 0;
			vis[t] = 0;
		}
	}
}

int main(){
	
	int n, cnt = 0;
	
	getPrime();
	
	while(cin >> n){
		if(cnt != 0){
			cout << endl;
		}
		//从PDF复制有两个空格，但是会提示格式错误 
		printf("Case %d:\n", ++cnt);
		memset(vis, 0, sizeof(vis));
		ans[0] = ans[1] = vis[1] = 1;		
		dfs(n);
	}
	
	return 0;
}
