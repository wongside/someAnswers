#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

char buf[1005];

int main(){
	string s;
	int n;
	cin >> n;
	cin.getline(buf, 1000);
	while(n--){
		memset(buf, 0, sizeof(buf));
		cin.getline(buf, 1000);
		int cnt = 1000;
		while(!isgraph(buf[cnt])){
			cnt--;
		}
		for(int i = 0; i <= cnt; i++){
			cout << buf[i];
		}
		cout << endl << endl;
	}
	while(cin >> s){
		cout << s << endl << endl;
	}
	
	return 0;
}
