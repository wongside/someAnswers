#include <iostream>
using namespace std;

int judge(char p1, char p2){
	if(p1 + p2 == 'P' + 'R'){
		if(p1 == 'P'){
			return  1;
		}
	}
	if(p1 + p2 == 'R' + 'S'){
		if(p1 == 'R'){
			return  1;
		}
	}
	if(p1 + p2 == 'S' + 'P'){
		if(p1 == 'S'){
			return  1;
		}
	}
	return 0;
}

int main(){
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int win1 = 0;
		int win2 = 0;
		char p1, p2;
		for(int i = 0; i < n; i++){
			cin >> p1 >> p2;
			win1 += judge(p1, p2);
			win2 += judge(p2, p1);
		}
		if(win1 > win2){
			cout << "Player 1" << endl;
		}else if(win1 < win2){
			cout << "Player 2" << endl;
		}else{
			cout << "TIE" << endl;
		}
	}
	return 0;
}
