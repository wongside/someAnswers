#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	cin >> s;
	int len = s.length();
	int ans  = 0; 
	for(int i = 0; i < len; i++){
		if(s[i] == '('){
			ans++;
		}else if(s[i] == ')'){			
			ans--;
			if(ans < 0){
				break;
			}
		}
		
	}
	if(ans == 0){
		cout << "YES";
	}else{
		cout << "NO";
	}
	
	return 0;
} 
