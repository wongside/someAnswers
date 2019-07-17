#include <iostream>
using namespace std;

char tag[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	
	int n;
	while(cin >> n){
		printf("2 %d %d\n", n, n);
		for(int k = 0; k < 2; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					printf("%c", k? tag[i]: tag[j]);
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
	
	
	return 0; 
} 
