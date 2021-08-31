#include <iostream>
using namespace std;

int tab[105];

int main(){
	
	int n, m, p = 0;
	cin >> n >> m;
	if(n == 0){
		return 0;
	}
	while(1){
		for(int i = 0; i < m; i++){
			int flag = 0;
			do{				
				if(++p > n){
					p = 1;
					if(++flag > m){
						return 0;
					}
				}				
			}while(tab[p] != 0);
		}
		tab[p] = 1;
		cout << p << " ";
	}
			
	
	return 0;
} 
