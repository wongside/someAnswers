#include <iostream>
using namespace std;

int main(){
	int a = 0;
	int b = 0;
	for(int i = 1; i <= 1000; i++){
		int temp = i;
		int num0 = 0;
		int num1 = 0;
		while(temp > 0){
			if(temp%2 == 1){
				num1++;
			}else{
				num0++;
			}
			temp /= 2; 
		}
		if(num1 > num0){
			a++;
		}else{
			b++;
		}
	}
	cout << a << " " << b;
	
	return 0;
}
