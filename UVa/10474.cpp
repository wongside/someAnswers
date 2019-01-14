#include <iostream>
#include <algorithm> 
using namespace std;

int tab[10000];

int main(){
	int n, q, kase = 1;
	while((cin >> n >> q) && n != 0){
		for(int i = 0; i < n; i++){
			cin >> tab[i];
		}
		sort(tab, tab + n);
		cout << "CASE# " << kase++ << ":\n";
		int x;
		while(q--){
			cin >> x;
			int p = lower_bound(tab, tab+n, x) - tab;
			if(tab[p] == x){
				printf("%d found at %d\n", x, p+1);
			}else{
				printf("%d not found\n", x);
			}
		}
	}
	
	return 0;
}
