#include <iostream>
using namespace std;

int tab[100005];

int main(){
	
	int m, n;
	cin >> n;
	for(int i = 0; cin >> m; i++){
		tab[m]++; 
	}
	for(int i = 0; i < 10004; i++){
		if(tab[i] == 2){
			n = i;
		}
		if(i > 0 && tab[i-1] > 0 && tab[i] == 0 && tab[i+1] > 0){
			m = i;
		}
	}
	cout << m << " " << n;
	
	return 0;
}
