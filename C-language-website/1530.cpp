#include <iostream>
#include <algorithm>
using namespace std;

int tab[4];

int f(int a, int b){
	return a > b;
}

int g(int a, int b){
	return a < b;
}

int main(){
	int num, max, min, cnt = 0, last = -1;
	cin >> num;
	while(num != last){
		last = num;
		for(int i = 0; i < 4; i++){
			tab[i] = num % 10;
			num /= 10;
		}
		sort(tab, tab+4, f);
		max = 1000 * tab[0] + 100 * tab[1] + 10 * tab[2] + tab[3];
		sort(tab, tab+4, g);
		min = 1000 * tab[0] + 100 * tab[1] + 10 * tab[2] + tab[3];
		num = max - min;
		cnt++;
	}
	
	cout << cnt-1; 
	
	return 0;
}
