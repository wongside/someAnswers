#include <iostream>
#include <memory.h>
using namespace std;

int tab[10];
int n, sum = 0;

int ok(int a, int b){
	memset(tab, 0, sizeof(tab));
	int cnt = 0;
	int t = (n-a) * b;
	while(a > 0){
		tab[a%10]++;
		a /= 10;
	}
	while(b > 0){
		tab[b%10]++;
		b /= 10;
	}
	while(t > 0){
		tab[t%10]++;
		t /= 10;
	}
	if(tab[0] != 0){
		return 0;
	}
	for(int i = 1; i < 10; i++){
		if(tab[i] == 1){
			cnt++;			
		}
	}
	if(cnt == 9){
		return 1;
	}
	return 0;
}

int check(int x){
	memset(tab, 0, sizeof(tab));
	while(x > 0){
		tab[x%10]++;
		x /= 10;
	}
	if(tab[0] != 0){
		return 1;
	}
	for(int i = 1; i < 10; i++){
		if(tab[i] > 1){
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		if(check(i)){
			continue;
		}
		for(int j = 1; j < 9999; j++){
			if(check(j)){
				continue;
			}
			if(ok(i,j)){
				sum++;
			}
		}
	}
	cout << sum;
	
	return 0;
}
