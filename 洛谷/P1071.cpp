#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

set<char> s;
map<char,char> m;


int main(){
	int flag = 1;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for(unsigned int i = 0; i < s1.length(); i++){
		s.insert(s1[i]);
		if(m[s1[i]] == 0){
			m[s1[i]] = s2[i];
		}else if(m[s1[i]] != s2[i]){
			flag = 0;
			break;
		}		
	}
	if(s.size() != 26){
		flag = 0;
	}
	
	if(flag){
		for(unsigned int i = 0; i < s3.length(); i++){
			cout << m[s3[i]];
		}
	}else{
		cout << "Failed";
	}
		
	
	return 0;
} 
