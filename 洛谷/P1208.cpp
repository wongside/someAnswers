#include <iostream>
#include <algorithm>
using namespace std;

struct P{
	int prc;
	int out;
};

P t[5000+10];

int f(P a, P b){
	return a.prc < b.prc;
}

int main(){
	long long sum = 0;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> t[i].prc >> t[i].out;
	}
	sort(t,t+m,f);
	for(int i = 0; i < m && n > 0; i++){
		if(n >= t[i].out){
			n -= t[i].out;
			sum += t[i].out * t[i].prc;
		}else{
			sum += n * t[i].prc;
			n = 0;
		}
	}
	cout << sum;
	
	return 0;
}
