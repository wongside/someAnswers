#include <iostream>
using namespace std;

int tab[2000000];

int main(){
	long long n, k, t, sum = 0, num = 1;
	cin >> n >> k >> t;
	for(long long i = 0; i < 2*k; i++){
		num += i;
		num %= k;
		tab[i] = num;
	}
	for(int i = 0; i < t; i++){
		sum += tab[(i*n)%(2*k)];
	} 
	cout << sum;
	
	return 0;
} 
