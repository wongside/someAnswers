#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p1,p2,p3;

string f(string s){
	string ans = "-";
	int flag = 0;
	if('a' <= s[0] && s[0] <= 'z' &&
	   'a' <= s[2] && s[2] <= 'z'){
		flag = 1;
	}
	if('0' <= s[0] && s[0] <= '9' &&
	   '0' <= s[2] && s[2] <= '9'){
		flag = 2;
	}
	if(s[2] > s[0]){
		flag *= 10;
	}
	if(flag >= 10){
		ans = "";	
		for(char i = s[0]+1; i < s[2]; i++){
			for(int k = 0; k < p2; k++){
				if(p1 == 2 && flag == 10){
					ans += toupper(i);
				}else if(p1 == 3){
					ans += '*';
				}else{
					ans += i;
				}
			}
			if(p3 == 2 && ans.length() > 0){
				reverse(ans.begin(),ans.end());
			}
		}
	}
	return ans;
}


int main(){
	int pos = 0;
	string s,ans;
	cin >> p1 >> p2 >> p3;
	cin >> s;
	for(unsigned int i = 1; i < s.length()-1; i++){
		if(s[i] == '-'){			
			ans += s.substr(pos,i-pos);					
			ans += f(s.substr(i-1,3));
			pos = i+1;
		}
	}
	ans += s.substr(pos);
	cout << ans;
	
	return 0;
}
