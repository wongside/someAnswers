#include <iostream>
#include <memory.h>
using namespace std;
char tab[50];
int main(){
	int ans[4];
	while(scanf("%s",tab) == 1){
		for(int i = 0; i < 30; i++){
			if(tab[i] == '.'){
				tab[i] = ' ';
			}
		}
		if(sscanf(tab, "%d%d%d%d", ans+0, ans+1, ans+2, ans+3) == 4 &&
			0 <= ans[0] && ans[0] <= 255 && 0 <= ans[1] && ans[1] <= 255 && 
			0 <= ans[2] && ans[2] <= 255 && 0 <= ans[3] && ans[3] <= 255){
			cout << "Y" << endl;
		}else{
			cout << "N" << endl;
		}
		memset(tab, 0, sizeof(tab));
	}
	
	return 0;
} 
