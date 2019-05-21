#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	long long n;
	cin >> n;
	long long tmp;
	for(long long i = 1; i < n; i++){
		long long fx = (i * (i+1)) / 2;
		tmp = fx + n;
		if(8*tmp + 1 >= 0){
			long long y = (sqrt(8*tmp + 1) - 1) / 2;
			if(((y * (y+1)) / 2) == tmp && y > i+1){
				cout << i+1 << " " << y << endl;
			}
		}		
	}
	
	return 0;
}
