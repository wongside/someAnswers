#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

int cmp(int a, int b){
	return a > b;
}

int main(){
	string s1, s2;
	int cnt1[26];
	int cnt2[26];
	int len;
	while(cin >> s1 >> s2){
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		len = s1.size();
		for(int i = 0; i < len; i++){
			cnt1[s1[i]-'A']++;
			cnt2[s2[i]-'A']++;
		}
		sort(cnt1, cnt1+26, cmp);
		sort(cnt2, cnt2+26, cmp);
		int flag = 1;
		for(int i = 0; i < 26; i++){
			if(cnt1[i] != cnt2[i]){
				flag = 0;
				break;
			}
		}
		if(flag){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	
	return 0;
}
