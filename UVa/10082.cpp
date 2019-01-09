#include <iostream>
using namespace std;

char tab[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
	int ch;
	while((ch = getchar()) != EOF){
		int f = 1;
		for(int i = 0; i < 47; i++){
			if(tab[i] == ch){
				cout << tab[i-1];
				f = 0;
				break;
			}
		}
		if(f){
			cout << (char)ch;
		}
	} 
	
	return 0;
}
