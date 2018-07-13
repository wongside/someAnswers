#include <iostream>
#include <math.h>
#include <set>
using namespace std;
#define LOCAL 1

set<int> s;
int x,y,z,n,base;
int test(void){
	if(x >= 0 && z >= 0){
		int A = x + y + z;
		int B = x / 10 + z;
		if(n == A + B){
			return 1;
		}
	}
	return 0;
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	cin >> n;
	while(n){
		for(int i = 0; i < 10; i++){
			base = pow(10,i);	
			for(int j = 0; j < 10; j++){
				y = j * base;
				if(i < 5){
					for(z = 0; z < base; z++){
						x = ((n - y - 2*z) * 10) / 11;
						if(test()){
							s.insert(x + y + z);
						}
					}					
				}else{
					for(x = 1000000000; x > base; x--){
						z = n - y - 11 * x / 10;
						if(test()){
							s.insert(x + y + z);
						}
					}					
				}
			}
					
			if(s.size()){
			    set<int>::iterator iter=s.begin();			    
			    while(iter!=s.end())
			    {
			        cout << *iter << " ";
			        ++iter;
			    }				
			}else{
				cout << "No solution.";
			}			
		}		
		cout << endl;
		cin >> n;
	}	
	
	return 0;
}
