#include <iostream>
using namespace std;

int tab[105];

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			tab[i] = ((i+1)*(i+2))/2;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n-i; j++){
				if(i != 0){
					tab[j] += i+j;
				}				
				cout << tab[j] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}
