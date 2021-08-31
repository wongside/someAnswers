#include <iostream>
using namespace std;

int tab[100000+10];

int f(int n, int k){
	if(n <= 1){
		return 1;
	}
	if(tab[n] == 0){
		for(int i = 1; i <= k && i <= n; i++){
			tab[n] += f(n-i,k);			
		}
		tab[n] %= 100003;
	}
	return tab[n];
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << f(n, k);
	return 0;
} 
