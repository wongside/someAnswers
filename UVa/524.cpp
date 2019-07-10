#include <iostream>
#include <cstring>
using namespace std;

int prime[100]; // ������prime[0]Ϊ�������� 

/*
Eulerɸ����ȡ���� 
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
//  ��ӡ������	
//	for(int i = 1; i <= prime[0]; i++){	
//		cout << prime[i] << endl;
//	}
}

int vis[20];	// �ж������Ƿ��Ѿ�ʹ�ù� 
int ans[20];	// �洢��� 

void dfs(int n){
	
	if(ans[0] == n){
		int t = ans[n] + 1;
		for(int i = 1; i <= prime[0]; i++){
			if(t == prime[i]){ //�ж����һ�����͵�һ���� 
				for(int j = 1; j <= ans[0]; j++){ //��ӡ��� 
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
		//��PDF�����������ո񣬵��ǻ���ʾ��ʽ���� 
		printf("Case %d:\n", ++cnt);
		memset(vis, 0, sizeof(vis));
		ans[0] = ans[1] = vis[1] = 1;		
		dfs(n);
	}
	
	return 0;
}
