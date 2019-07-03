#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, string> m;

string stand(string t){
	string s = t;
	int len = s.length();
	for(int i = 0; i < len; i++){
		s[i] = tolower(s[i]);
	}
	sort(s.begin(), s.end());
	return s;
}

vector<string> ans;

int main(){
	string s;
	while(cin >> s && s[0] != '#'){
		string t = stand(s);
		if(m.count(t)){
			m[t] = " ";
		}else{
			m[t] = s;
		}
	}
	map<string, string>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		if(it->second != " "){
			ans.push_back(it->second);
		}
	}
	sort(ans.begin(), ans.end());
	int len = ans.size();
	for(int i = 0; i < len; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}

/*
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
noel dire Disk mace Rob dries
#
*/
