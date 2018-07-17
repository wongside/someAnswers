#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string st(string s){
	reverse(s.begin(),s.end());
	while(s[0] == '0' && s.length() > 1){
		s = s.substr(1);
	}
	return s;
}

int main(){
	
	int type = 1, pos = -1;
	string s,ans;
	cin >> s;
	for(unsigned int i = 0; i < s.length(); i++){
		if(s[i] == '.'){
			type = 2;
			pos = i;
			break;
		}
		if(s[i] == '/'){
			type = 3;
			pos = i;
			break;
		}
		if(s[i] == '%'){
			type = 4;
			pos = i;
			break;
		}
	}
	if(type == 1){
		ans = st(s);
	}else if(type == 2){				
		ans = st(s.substr(0,pos)) + ".";
		string tmp = s.substr(pos+1);
		reverse(tmp.begin(),tmp.end());
		tmp = st(tmp);
		reverse(tmp.begin(),tmp.end());
		ans += tmp;		
	}else if(type == 3){
		ans = st(s.substr(0,pos)) + "/" 
				+ st(s.substr(pos+1));
	}else{
		ans = st(s.substr(0,pos)) + "%"; 
	}
	cout << ans;
	
	return 0;
}
