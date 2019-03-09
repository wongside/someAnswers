#include <iostream>
using namespace std;

int gcd(int m, int n){
	if(m < n){
		int t = m;
		m = n;
		n = t;
	}
	int tmp = m % n;
	if(tmp == 0){
		return n;
	}
	return gcd(n, tmp);
}

int main(){
	
	int a, b, c;
	cin >> a >> b >> c;
	int t = (a*b) / gcd(a, b);
	cout << (t*c) / gcd(t, c);
	
	return 0;
}
