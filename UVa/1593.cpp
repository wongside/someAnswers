#include <iostream>
using namespace std;

char tab[1010][200] = {'\0'};
int flag[200] = {0};
char str[100];

int main(){
	int n = 0;
	for(; gets(tab[n]) != 0;n++);
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < 180 && sscanf(tab[i][j],"%s",str);){
			int k = 0;
			for(; k < 100 && str[k] != '\0'; k++);
			j += k;
			if(k > tab[sum]){
				tab[sum] = k;
			}
		}		
	}
	
	
//	for(int i = 0; i < n; i++){
//		cout << tab[i] << endl;
//	}
	
	
	return 0;
}
