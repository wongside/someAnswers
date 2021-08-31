#include <iostream>
using namespace std;

int tab[1000010];

int main(){
	long long m, n;
	cin >> m >> n;
	long long cnt = 1;
	while(1){		
		while(tab[++cnt] != 0);
		if(cnt >= n){
			break;
		}
		long long now = 0;
		while(now < n){
			for(long long i = 0; i < cnt;){
				if(tab[++now] == 0){
					i++;
				}
			}
			if(now < n){
				tab[now] = 1;
			}			
		}
	}
	long long ans = 0;
	while(cnt > m+1){
		if(tab[--cnt] == 0){
			ans++;
		}		
	}
	cout << ans;
	
	return 0;
}
