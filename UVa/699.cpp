#include <iostream>
#include <memory.h>
using namespace std;

int sum[10000], fail = 0;

void build(int p, int s){
	int v;
	cin >> v;
	if(v == -1 ){
		if(s){
			fail = 1;
		}
		return;
	}
	build(p-1, 0);
	build(p+1, 0);
	sum[p] += v;
}

bool input(){
	memset(sum, 0, sizeof(sum));
	fail = 0;
	build(5000, 1);
	if(!fail){
		return true;
	}
	return false;
}

int main(){
	int kase = 1;
	while(input()){
		int p = 0;
		while(sum[p]==0) {
			p++;
		}
		cout << "Case " << kase++ << ":\n" << sum[p++];
		while(sum[p++] != 0){
			cout << " " << sum[p-1];
		}
		cout << endl << endl;
	}
	
	return 0;
}
