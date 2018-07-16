#include <iostream>
using namespace std;

string int_to_string(int n){
	char tmp[10];
	sprintf(tmp,"%d",n);
	string s(tmp);
	return s;
}

int main(){
		
//	string s = "";
//	for(int i = 0; i < 10; i++){
//		s += int_to_string(i);
//	}
//	cout << s;	
	int n,t;
	cin >> n;
	for(int i = 0; i < n; i++){
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
