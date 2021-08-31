#include <iostream>
#include <memory.h>
using namespace std;

int num[100010];
int tmp[100010];
int tab[1000010];
long long ans[100010];

int bit(int x){
	return x&(-x);
}

void update(int idx, int add){
	idx++;
	while(idx <= 1000001){
		tab[idx] += add;
		idx += bit(idx);
	}
}

int sum(int idx){
	idx++;
	int tmp = 0;
	while(idx > 0){
		tmp += tab[idx];
		idx -= bit(idx);
	}
	return tmp;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
		update(num[i], 1);
		tmp[i] = i - sum(num[i]);		
	}
	memset(tab, 0, sizeof(tab));
	for(int i = n; i > 0; i--){
		update(num[i], 1);
		tmp[i] += sum(num[i]-1);
	}
	long long sum = 0;
	for(int i = 1; i <= 100010; i++){
		ans[i] = ans[i-1] + i;
	}
	for(int i = 1; i <= n; i++){		
		sum += ans[tmp[i]];
	}
	cout << sum;
	
	return 0;
}
