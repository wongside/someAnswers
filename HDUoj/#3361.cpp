#include <iostream>
#include <string.h> 
using namespace std;

#define LOCAL 0

int t[26];

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
	cout << "#########################"<< endl;
#endif

	int ch;
	while((ch = cin.get()) != EOF){	
		cin.putback(ch);
		memset(t,0,sizeof(t));
		while((ch = cin.get()) != '\n'){
			if(ch == EOF)
				break;
			if('a' <= ch && ch <= 'z'){
				t[ch-'a']++;
			}			
		}		
		for(int i = 0;i < 26;i++){
			cout << char('a'+i) << ":" << t[i];
				cout << endl;			
		}
		cout << endl;
	}
	
	return 0;
}
