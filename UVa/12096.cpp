#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

map<set<int>, int> m;
vector< set<int> > v;

int find(set<int> s){
	if(m.count(s) == 0){
		v.push_back(s);
		m[s] = v.size()-1;
	}
	return m[s];
} 

int main(){
	int t, n;
	string s;
	cin >> t;
	
	while(t--){
		cin >> n;
		stack<int> sta;
		while(n--){
			set<int> a, b, c;
			cin >> s;
			
			if(s[0] == 'P'){
				c = set<int>();
			}else if(s[0] == 'D'){
					c = v[sta.top()];
			}else{
				a = v[sta.top()];
				sta.pop();
				b = v[sta.top()];
				sta.pop();
				if(s[0] == 'U'){
					set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
				}else if(s[0] == 'I'){
					set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
				}else if(s[0] == 'A'){
					c = b;
					c.insert(find(a));
				}
			}
			
			sta.push(find(c));
			cout << c.size() << endl;
		}
		cout << "***" << endl;
	}
	
	return 0;
}


/*
2
9
PUSH
DUP
ADD
PUSH
ADD
DUP
ADD
DUP
UNION
5
PUSH
PUSH
ADD
PUSH
INTERSECT
*/
