#include <iostream>
using namespace std;

const int maxn = 10000005;

int tab[maxn];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 2; i <= n; i++){
		if(tab[i] == 0){
			tab[++tab[0]] = i;
		}
		for(int j = 1; j <= tab[0] && tab[j] * i <= n; j++){
			tab[tab[j] * i] = 1;
		}
	}
	int t;
	
	for(int i = 1; i <= m; i++){
		cin >> t;
		if(*lower_bound(tab+1, tab+tab[0]+1, t) == t){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	} 
	
	
	return 0;
} 
