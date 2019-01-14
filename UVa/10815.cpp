#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

set<string> dict;

int main(){
	string s, tmp;
	while(cin >> s){
		for(int i = 0; i < (int)s.size(); i++){
			if(isalpha(s[i])){
				s[i] = tolower(s[i]);
			}else{
				s[i] = ' ';
			}			
		}
		stringstream ss(s);
		while(ss >> tmp){
			dict.insert(tmp);
		}
	}	
	for(set<string>::iterator it = dict.begin(); it != dict.end(); it++){
		cout << *it << endl;
	}
	
	return 0;
}
