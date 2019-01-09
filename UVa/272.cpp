#include <iostream>
using namespace std;

int main(){
	
	
	int c, p = 1;

	while((c = getchar()) != EOF){
		if(c == '"'){
			if(p == 1){
				cout << "``";
			}else{
				cout << "''";
			}
			p = !p;
		}else{
			cout << (char)c;
		}
	}
	
	return 0;
}
