#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int n, t;
	string s, ts;
	cin >> n >> s;
	for(int i = 1; i < n; i++){
		cin >> ts;
		t = s.find(ts[0]);
		s.erase(t, 1);
		s.insert(t, ts);
	}
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(s[i] != '*'){
			cout << s[i];
		}
	}
	
	return 0;
}
