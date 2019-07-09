#include <iostream>
using namespace std;

bool ok(int a, int b){
	int tab[10] = {0};
	if(b < 10000){
		tab[0]++;
	}
	while(a != 0){
		tab[a%10]++;
		a /= 10;
	}
	while(b != 0){
		tab[b%10]++;
		b /= 10;
	}
	for(int i = 0; i < 10; i++){
		if(tab[i] != 1){
			return false;
		}
	}
	return true;
}

int main(){
	
	int n, flag, cnt = 0;
	while(cin >> n && n != 0){
		flag = 0;
		
		if(cnt++ > 0){
			printf("\n");
		}		
		for(int i = 1234; i < 99999; i++){
			if(ok(n * i, i)){
				flag++;
				printf("%d / %s%d = %d\n", n*i, i < 10000? "0": "", i, n);
			}
		}
		if(flag == 0){
			printf("There are no solutions for %d.\n", n);
		}
		
	}
	
	return 0;
}
