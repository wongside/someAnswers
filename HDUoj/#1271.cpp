#include <iostream>
#include <math.h>
using namespace std;
#define LOCAL 1

int test(int a, int b){
	
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int n;
	cin >> n;
	while(n){
		for(int i = 0; i < 10; i++){
			int x = n / pow9(10,i);
			if(x == 0){
				break;
			}
			y = x % 10;
			if(x < 10 && y == 0){
				continue;
			}
			for(int j = 0; j <= y; j++){
				
				int tmp = j * (int)pow(10,i);
				int a = (n + tmp)/2;
				int b = n -a;
				if(test(a,b)){
					cout << a << " "; 
				} 
			}
		}		
		cout << endl;
		cin >> n;
	}

	
	
	return 0;
}
