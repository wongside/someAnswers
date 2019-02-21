#include <iostream>
using namespace std;

int main(){
	int n, a, b, cnt;
	cin >> n;
	while(n--){
		cin >> a >> b;
		cnt = (a - 1) / 2;	
		for(int k = 0; k < b; k++){
			int space = 0;
			for(int i = 0; i < a; i++){		
				if(!(k != 0 && i == 0)){
					for(int j = 0; j < space; j++){
						cout << " ";
					}
					cout << "X";
					for(int j = 0; j < (cnt-space)*2-1; j++){
						cout << " ";
					}
					if(i != cnt){
						cout << "X";
					}
					cout << endl;
				}
				if(i < cnt){
					space++;
				}else{
					space--;
				}
			} 
		}
		if(n != 0){
			cout << endl;
		}
	} 
	
	return 0;
}
