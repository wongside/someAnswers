#include <iostream>
#include <algorithm>
using namespace std;

int tab[1000+10][1000+10];

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> tab[i][j];
		}
	}
	
	for(int i = n-1;i > 0;i--){
		for(int j = 1; j <= i; j++){
			tab[i][j] += max(tab[i+1][j],tab[i+1][j+1]);
		}
	}
	cout << tab[1][1];

	return 0;
} 
