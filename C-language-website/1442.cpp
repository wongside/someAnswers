#include <iostream>
using namespace std;

char tab[150][150];

void f(int n){
	for(int i = 0; i < 4*n+1; i++){
		tab[75 - (2*n+2)][75 - (2*n+2) + 2 + i] = '$';
		tab[75 + (2*n+2)][75 - (2*n+2) + 2 + i] = '$';
		tab[75 - (2*n+2) + 2 + i][75 - (2*n+2)] = '$';
		tab[75 - (2*n+2) + 2 + i][75 + (2*n+2)] = '$';
	}
	for(int i = 0; i < 3; i++){
		tab[75 - (2*n+2) + i][75 - (2*n+2) + 2] = '$';
		tab[75 - (2*n+2) + i][75 + (2*n+2) - 2] = '$';
		
		tab[75 - (2*n+2) + 2][75 - (2*n+2) + i] = '$';
		tab[75 - (2*n+2) + 2][75 + (2*n+2) - i] = '$';
		
		tab[75 + (2*n+2) - 2][75 - (2*n+2) + i] = '$';
		tab[75 + (2*n+2) - 2][75 + (2*n+2) - i] = '$';
		
		tab[75 + (2*n+2) - i][75 - (2*n+2) + 2] = '$';
		tab[75 + (2*n+2) - i][75 + (2*n+2) - 2] = '$';	
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = -2; i <= 2; i++){
		tab[75 + i][75] = '$';
		tab[75][75 + i] = '$';
	}
	for(int i = 1; i <= n; i++){
		f(i);
	}
	int span = 2 * n + 2;
	for(int i = -span; i <= span; i++){
		for(int j = -span; j <= span; j++){
			if(tab[75+i][75+j] == '$'){
				cout << tab[75+i][75+j];
			}else{
				cout << '.';
			}
			
		}
		cout << endl;
	} 
	
	return 0;
}
