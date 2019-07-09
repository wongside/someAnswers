#include <iostream>
using namespace std;

int tab[10000][2];

int main(){
	
	int k;
	while(cin >> k){
		tab[0][0] = 0;
		for(int y = k+1; y <= 2*k; y++){
			int x = (k*y) / (y-k);
			if(x*y == k * (x + y)){
				int tmp = ++tab[0][0];
				tab[tmp][0] = x;
				tab[tmp][1] = y;
			}
		}
		cout << tab[0][0] << endl;
		for(int i = 1; i <= tab[0][0]; i++){
			printf("1/%d = 1/%d + 1/%d\n", k, tab[i][0], tab[i][1]);
		}
	}
	
	return 0;
} 
