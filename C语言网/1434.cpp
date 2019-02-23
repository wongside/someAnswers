#include <iostream>
using namespace std;

int n;

int f(int t){
	int tab[10], len = 0, sum = 0;
	while(t != 0){
		tab[len++] = t % 10;
		t /= 10;
		sum += tab[len-1];
	}
	if(sum != n){
		return 0;
	}	
	for(int i = 0; i < len/2; i++){
		if(tab[i] != tab[len - 1 - i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	int flag = 1;
	cin >> n;
	for(int i = 10000; i <= 999999; i++){
		if(f(i)){
			flag = 0;
			cout << i << endl;
		}
	}
	if(flag){
		cout << -1;
	}
	
	return 0;
}
