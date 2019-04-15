#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull tab[10000000];
ull n, m, p, ans = 0;

ull f(ull n){
	if(n < 3){
		return 1;
	}
	if(n >= 10000000){
		return (f(n-1)%p + f(n-2)%p)%p;
	}
	if(tab[n] == 0){
		tab[n] = (f(n-1)%p + f(n-2)%p)%p;
	}
	return tab[n];
}

int main(){
	tab[1] = tab[2] = 1;
	cin >> n >> m >> p;
	if(m > n){
		f(m);
	}else{
		f(n);
	}
	for(ull i = 1; i <= n; i++){
		ans = (ans + f(i)) % p;
		ans %= f(m);
	}
	cout << ans;
	
	return 0;
}
