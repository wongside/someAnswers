#include <iostream>
using namespace std;

int tab[40][40];
int n;

void f(int x, int y){
	tab[x][y] = -1;
	if(y - 1 >= 0 && tab[x][y-1] == 0){
		f(x, y-1);
	}
	if(y + 1 <= n+1 && tab[x][y+1] == 0){
		f(x, y+1);
	}
	if(x - 1 >= 0 && tab[x-1][y] == 0){
		f(x-1, y);
	}
	if(x + 1 <= n+1 && tab[x+1][y] == 0){
		f(x+1, y);
	}
}

int main(){
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> tab[i][j];
		}
	}
	f(0, 0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(tab[i][j] == 0){
				tab[i][j] = 2;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(tab[i][j] == -1){
				cout << 0 << " ";
			}else{
				cout << tab[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	
	return 0;
}  
