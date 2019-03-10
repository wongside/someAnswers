#include <iostream>
#include <string>
using namespace std;

string stand(string s){ 
	for(unsigned int i = 0; i < s.length(); i++){
		s[i] = tolower(s[i]);
	} 
	return s;
	
}

int main(){
//	freopen("datain.txt","r",stdin);
//	freopen("dataout.txt","w",stdout);
	char ch;
	int sum = 0, first = -1,w = 0;
	string s;
	cin >> s;
	string word = stand(s);
	while((ch = getchar()) != '\n');
//	cout << "a" << ch << "b";
	while(1){
		string t = "";
		while((ch = getchar()) == ' ');
		if(ch == '\n' || ch == EOF){
			break;
		}
		t += ch;
		while(isalpha(ch = getchar())){
			t += ch;
		}
		if(word == stand(t)){
			sum++;
			if(first == -1){
				first = w;
			}
		}
		w++;		
	}
	if(first == -1){
		cout << -1;
	}else{
		cout << sum << " " << first;
	}
	
	return 0;
}
