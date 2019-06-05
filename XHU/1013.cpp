#include <iostream>
#include <algorithm>
using namespace std;

int tab[105];

int main(){
	
	int n;
	while(cin >> n && n != 0){
		for(int i = 0; i < n; i++){
			cin >> tab[i];
		}
		sort(tab, tab+n);
		int minStateNum = (n / 2) + 1;
		int sum = 0;
		for(int i = 0; i < minStateNum; i++){
			sum += (tab[i]/2) + 1;
		}
		cout << sum << endl;
	}
	
	
	return 0;
} 
