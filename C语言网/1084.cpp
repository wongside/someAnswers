#include <iostream>
using namespace std;

int tab[100000];

int main(){
	
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		for(int j = 2; i*j <= n; j++){
			tab[i*j] = 1;
		}
	}
	for(int i = 2; i < n; i++){
		if(!tab[i])
			cout << i << endl;
	}
	
	return 0;
}
