#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[25];
int tab[25][25];
int n, ans = 0;

void check(int a, int b){
	int la = str[a].length();
	int lb = str[b].length();
	for(int i = 1; i < la && i < lb-1; i++){
		if(str[a].substr(la-i) == str[b].substr(0,i)){
			tab[a][b] = lb - i;
		}
	}
}


void f(int a, int sum){
	tab[a][n]++;
	for(int i = 0; i < n; i++){
		if(tab[a][i] != 0 && tab[i][n] < 2){
			f(i,sum+tab[a][i]);
		}			
	}
	tab[a][n]--;
	if(sum > ans){			
		ans = sum;
	}
}


int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	cin >> str[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			check(i, j);
		}
	}
	
	for(int i = 0; i < n; i++){
		if(str[i][0] == str[n][0]){
			f(i,str[i].length());
		}
	}
	
	cout << ans;
	
	
	return 0;
}
