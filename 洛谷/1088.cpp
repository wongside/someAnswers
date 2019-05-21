#include <iostream>
#include <algorithm>
using namespace std;

int tab[10005];

int main(){
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> tab[i];
	}
	while(m--){
		next_permutation(tab, tab+n);
	}
	for(int i = 0; i < n; i++){
		cout <<  tab[i] << " ";
	}
	
	return 0;
}
