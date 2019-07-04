#include <iostream>
#include <algorithm>
using namespace std;

string tab[105];

void print(string s, int len, char ch){
	cout << s;
	len = len - s.length();
	for(int i = 0; i < len; i++){
		cout << ch;
	}
}

int main(){
	
	int n, m, t;
	
	while(cin >> n){
		t = n;
		m = 0;
		while(n--){
			cin >> tab[n];
			m = max((int)tab[n].length(), m);			
		}
		sort(tab, tab+t);
		
		print("", 60, '-');
		printf("\n");
		int col = (60 - m) / (m + 2) + 1;
		int row = (t - 1) / col + 1;		
		for(int i = 0; i  < row; i++){
			for(int k = 0; k < col; k++){
				int tmp = k * row + i;
				if(tmp < t){
					print(tab[tmp], k == col - 1 ? m : m+2, ' ');
				}				
			}
			cout << endl;
		}
	}
	
	return 0;
} 
