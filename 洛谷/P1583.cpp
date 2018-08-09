#include <iostream>
#include <algorithm>
using namespace std;

struct P{
	int num;
	int wei;
};

P p[20000 + 10];

int f(P a, P b){
	if(a.wei == b.wei){
		return a.num < b.num;
	}
	return a.wei > b.wei;
}

int main(){
	int n, k, t, e[11];
	cin >> n >> k;
	for(int i = 1; i <= 10; i++){
		cin >> e[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> t;
		p[i].num = i;
		p[i].wei = t;
	}
	
	sort(p+1, p+1+n, f);
	
	for(int i = 1; i <= n; i++){
		p[i].wei += e[(i-1) % 10 + 1];
	}
	
	sort(p+1, p+1+n, f);
	
	for(int i = 1; i <= k; i++){
		cout << p[i].num << " ";
	}
	
	return 0;
} 
