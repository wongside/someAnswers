#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

string int_to_string(int n){
	char tmp[10];
	sprintf(tmp,"%d",n);
	string s(tmp);
	return s;
} 

string dan(int x, int z){	
	string s = "";
	//单项式系数符号判断 
	if(x > 0){
		s += "+";
	}else if(x < 0){
		s += "-";
		x = -x;
	}else{
		return s;
	}
	//单项式系数判断 
	if(x != 1){
		s += int_to_string(x);
	}
	//cout << "aaa" << endl; 
	//单项式指数判断 
	if(z == 0){
		return s;
	}else if(z == 1){
		s += "x";		
	}else if(z > 1){
		s += "x^" + int_to_string(z);
	}
	return s;
}


int main(){
	int n,t;
	string s;
	cin >> n;
	for(int i = 0; i <= n; i++){
		cin >> t;
		s += dan(t,n-i);
		if(i == 0 && t > 0){
			s = s.substr(1);
		}
		if(i == n && abs(t) == 1){
			s += "1";
		}
	}
	cout << s;
}
