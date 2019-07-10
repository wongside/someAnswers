#include <iostream>
using namespace std;

int tab[100];

int ok(int len){
	int t = len / 2;
	for(int i = 1; i <= t; i++){
		int flag = 1;
		for(int j = 0; j < i; j++){
			if(tab[len - j] != tab[len - j - i]){
				flag = 0;
			}
		}
		if(flag == 1){
			return 1;
		}
	}
	return 0;
}

int add(int p, int l){
	
	if(tab[p] >= l - 1){
		return add(p-1, l);
	}else{
		tab[p]++;
	}
	return p;
}

int main(){
	
	int n, l, cnt;
	while(cin >> n >> l && n != 0 && l != 0){
		tab[0] = cnt = 0;
		while(1){
			if(ok(tab[0])){
				tab[0] = add(tab[0], l);
				
			}else{
				if(cnt == n){
					for(int i = 1; i <= tab[0]; i++){
						if(i != 1){
							if((i-1) % 64 == 0){
								printf("\n");
							}else if((i-1) % 4 == 0){
								printf(" ");
							}
						}
						printf("%c", tab[i] + 'A');
					}
					cout << endl << tab[0] << endl;
					break;
				}
				cnt++;
				tab[++tab[0]] = 0;
			}
		}
		
	}
	
	return 0; 
} 
