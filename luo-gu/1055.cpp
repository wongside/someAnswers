#include <iostream>
#include <string>
using namespace std;


int main(){
	
	string s1,s2;
	cin >> s1;
	
	int n,sum = 0;
	if(s1[12] == 'X'){
		n = 10;
	}else{
		n = s1[12]-'0';
	}	
	s2 = s1.substr(0,1) + s1.substr(2,3) + s1.substr(6,5);
	for(int i = 0; i < 9;i++){
		int tmp = s2[i] - '0';
		sum += tmp * (i+1);
	}
	sum %= 11;
	if(sum == n){
		cout << "Right";
	}else{
		if(sum == 10){
			s1[12] = 'X';
		}else{
			s1[12] = '0' + sum;
		}
		cout << s1;		
	}
	
	
	return 0;
}
