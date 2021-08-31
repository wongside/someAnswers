#include <iostream>
using namespace std;

int tab[100];
int n;

int ok(){
	for(int i = 1; i < n; i++){
		if(tab[i] != tab[i-1]){
			return 0;
		}
	}
	return 1;
}

int main(){
	int first, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tab[i];
	}
	while(1){	
		first = tab[0] / 2;
		tab[0] /= 2;
		for(int i = 1; i < n; i++){
			tab[i-1] += tab[i] / 2;
			tab[i] /= 2;
		}
		tab[n-1] += first;
		if(ok()){
			break;
		}
		for(int i = 0; i < n; i++){
			if(tab[i]%2 == 1){
				tab[i]++;
				ans++;
			}
		}		
	}
	cout << ans;
	
	return 0;
}
