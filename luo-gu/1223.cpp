#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct P{
	int num;
	int tim;
};

P t[1000+10];

int f(P a, P b){
	return a.tim < b.tim;
}

int main(){	
	long long sum = 0;
	int n, wait = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i].tim;
		t[i].num = i + 1;
	}
	sort(t,t+n,f);
	for(int i = 0; i < n; i++){
		cout << t[i].num << " ";
		if(i != 0){
			wait += t[i-1].tim;
		}
		sum += wait;
	}
	double avg = sum / double(n);
	printf("\n%0.2f",avg);
	
	return 0;
}
