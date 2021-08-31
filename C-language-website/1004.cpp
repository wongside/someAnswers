#include <iostream>
using namespace std;

int tab[60][4];

void f(int n){
	if(n > 55)
		return;
	tab[n][1] = tab[n-1][3];
	tab[n][2] = tab[n-1][1];
	tab[n][3] = tab[n-1][2] + tab[n-1][3];
	f(n+1);
}

int main(){
	tab[1][3] = 1;
	f(2);
	int n;
	while(cin >> n && n){
		cout << tab[n][1] + tab[n][2] + tab[n][3] << endl;
	}
	
	return 0;
}
