#include <iostream>
#include <cstdio>
using namespace std;

string int_to_string(int n){
	char tmp[10];
	sprintf(tmp,"%d",n);
	string s(tmp);
	return s;
}

int main(){
	
	int n,t;
	cin >> n;
	for(int i = 0; i <= n; i++){
		cin >> t;
		string s = "";
		if(t > 0){
			if(i != 0){
				s += "+";
			}			
		}else if(t == 1){
			if(i != 0){
				s += "+";
			}			
		}else if(t == 0){
			continue;
		}
		
		s += int_to_string(t);
		if(t == 1 || t == -1){
			if(i != n) 
			s = s.substr(0,s.length()-1);
		}
		int tmp = n-i;
		if(tmp > 1){
			s += "x^";
			s += int_to_string(tmp);
		}else if(tmp == 1){
			s += "x";
		}
		cout << s;
	}
	
	return 0;
}
