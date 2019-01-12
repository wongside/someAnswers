#include <iostream>
using namespace std;

int tab[100100];

int main(){
	for(int i = 1; i <= 100000; i++){
		int x = i, y = i;
		while(x > 0){
			y += x % 10;
			x /= 10;
		}
		if(tab[y] == 0){
			tab[y] = i;
		}
	}
	int n, t;
	cin >> t;
	while(t--){
		cin >> n;
		cout << tab[n] << endl;
	}
	
	return 0;
}
