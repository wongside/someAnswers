#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> old;

int n = 1;
string a, b;
string r[10][2];

int bfs(set<string> now, int cnt){
	set<string> next;
	if(cnt > 10){
		return -1;
	}
	for(;now.size() > 0;){
		string s = *(now.begin());
		for(int i = 1; i < n; i++){
			unsigned int pos = s.find(r[i][0]);
			for(; pos < s.length(); pos = s.find(r[i][0],pos+1)){
				string tmp = s.substr(0,pos) + r[i][1] + 
							 s.substr(pos+r[i][0].length());
				if(tmp == b){
					return cnt;
				}
				if(old.count(tmp) == 0){
					next.insert(tmp);
				}
			}
		}
		now.erase(now.begin());
	}
	
	return bfs(next, cnt+1);
}

int main(){

	cin >> a >> b;
	for(; cin >> r[n][0] >> r[n][1]; n++);
	
	set<string> tmp;
	tmp.insert(a);
	old.insert(a);
	int  t = bfs(tmp,1);
	if(t == -1){
		cout << "NO ANSWER!";
	}else{
		cout << t;
	}
	
	return 0;
} 
