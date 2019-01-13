#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main(){
	string s1, s2;
	int n, cnt[26];
	while((cin >> n) && n != -1){
		
		int sum = 0, ok = 0;
		cin >> s1 >> s2;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < (int)s1.size(); i++){
			cnt[s1[i]-'a']++;
		}
		ok = s1.size();
		for(int i = 0; i < (int)s2.size(); i++){			
			if(cnt[s2[i]-'a'] > 0){
				ok -= cnt[s2[i]-'a'];
				cnt[s2[i]-'a'] = 0;
				if(ok == 0){
					break;
				}			
			}else{
				sum++;
				if(sum > 6){
					break;
				}
			}
		}
		cout << "Round " << n << endl; 
		if(ok == 0){
			cout << "You win.\n";
		}else if(sum > 6){
			cout << "You lose.\n";
		}else{
			cout << "You chickened out.\n";
		}
	}
	
	return 0;
}
