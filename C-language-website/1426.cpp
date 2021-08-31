#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> old;
string ans, s;


int f(set<string> now, int cnt){
	if(now.size() == 0){
		return -1;
	}
	set<string> last;
	set<string>::iterator it;
	for(it = now.begin(); it != now.end(); it++){
		string str = *it;
		int loc = str.find('.', 0);
		string tmp;
		if(loc - 3 >= 0){
			tmp = str;
			tmp[loc] = tmp[loc-3];
			tmp[loc-3] = '.';
			if(tmp == ans){
				return cnt;
			}
			if(old.count(tmp) == 0){
				last.insert(tmp);
			}
		}
		if(loc - 1 >= 0 && loc != 3 && loc != 6){
			tmp = str;
			tmp[loc] = tmp[loc-1];
			tmp[loc-1] = '.';
			if(tmp == ans){
				return cnt;
			}
			if(old.count(tmp) == 0){
				last.insert(tmp);
			}
		}
		if(loc + 3 < 9){
			tmp = str;
			tmp[loc] = tmp[loc+3];
			tmp[loc+3] = '.';
			if(tmp == ans){
				return cnt;
			}
			if(old.count(tmp) == 0){
				last.insert(tmp);
			}
		}
		if(loc + 1 < 9 && loc != 2 && loc != 5){
			tmp = str;
			tmp[loc] = tmp[loc+1];
			tmp[loc+1] = '.';
			if(tmp == ans){
				return cnt;
			}
			if(old.count(tmp) == 0){
				last.insert(tmp);
			}
		}
		old.insert(str);
	}
	return f(last, cnt+1);
}

int main(){
	set<string> now;
	cin >> s >> ans;
	now.insert(s);
	
	cout << f(now, 1);
	
	return 0;
}
