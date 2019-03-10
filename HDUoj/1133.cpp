#include <iostream>
using namespace std;


int f(int m, int n, int t){	
	int tmp = 0;
	if(m > 1){
		tmp += (m-1) * f(m-1, n, t+1);
	}else{
		tmp += 1;
	}
	
	if(t > 0){		
		if(n > 1){
			tmp += (n-1) * f(m, n-1, t-1);
		}else{
			tmp += 1;
		}
	}
	return tmp;
}


int main(){
	int m, n;
	for(int i = 1; cin >> m >> n; i++){
		if(m == 0 && n == 0){
			break;
		}
		cout << "Test #" << i << ":" << endl;
		if(m < n){			
			cout << 0 << endl;
		}else{
			cout << f(m, n, 0) << endl;
		}		
	}
	
	return 0;
} 
