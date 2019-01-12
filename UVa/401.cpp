#include <iostream>
#include <string>
using namespace std;

string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
string rul[] = {" -- is not a palindrome.",
				" -- is a regular palindrome.",
				" -- is a mirrored string.",
				" -- is a mirrored palindrome."};

char mirror(char ch){
	if(isalpha(ch)){
		return rev[ch-'A'];
	}else{
		return rev[ch+26-'1'];
	}
}

int main(){
	string s;
	while(cin >> s){
		int len = s.size();
		int a = 1, b = 1;
		int l = (len + 1) / 2;
		for(int i = 0; i < l; i++){
			if(s[i] != s[len-1-i]){
				a = 0;
			}
			if(mirror(s[i]) != s[len-1-i]){
				b = 0;
			}
		}
		cout << s << rul[2*b + a] << endl << endl;
	}
	
	return 0;
}
