#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

struct String{
	int sta;
	int end;
	char ch;
	String(){
	}
	String(int s, int e, char c){
		sta = s;
		end = e;
		ch  = c;
	}
};

struct cmp{
	bool operator()(String a, String b){
		if(a.ch == b.ch){
			return a.sta < b.sta;
		}
		return a.ch < b.ch;
	}
};

char str[105];

set<String, cmp> s;

int main(){
	
	
	int t, len;
	String tmp;
	set<String, cmp>::iterator it;
	
	cin >> t;
	while(t--){
		scanf("%s", str);
		len = strlen(str);
		
		s.clear();
		for(int i = 0; i < len; i++){
			tmp = String(i, i, str[i]);
			s.insert(tmp);
		}
		
		set<String, cmp> ps;
		while(s.size() > 1){
			it = s.begin();
			char ch = it->ch;
			ps.clear();
			for(; it != s.end(); it++){												
				if(it->ch == ch){
					int tt = (it->end)+1;
					if(tt >= len){
						tt = 0;
					}
					tmp = String(it->sta, tt, str[tt]);
					ps.insert(tmp);					
				}else{
					break;
				}
			}
			s = ps;
		}
		int pit = s.begin()->sta;
		int cnt = len;
		while(cnt--){
			printf("%c", str[pit++]);
			if(pit >= len){
				pit = 0;
			}
		}
		printf("\n");	
	}
		
	return 0;
} 
