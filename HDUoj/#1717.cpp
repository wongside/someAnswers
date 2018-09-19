#include <iostream>
#include <string>
using namespace std;

int main(){
	string a, b, s;
	int n, len, i;
	cin >> n;
	while(n--){
		cin >> s;
		
		a = s.substr() s.find('(');
		
		
		len = s.length();
		a = -1;
		b = -1;
		for(i = 2; i < len && s[i] != '('; i++){
			a *= 10;
			a += s[i] - '0';
		}
		for(i++; i < len && s[i] != ')'; i++){
			b *= 10;
			b += s[i] - '0';
		}
		cout << a << b << endl;
	}
	
	
	return 0;
} 
