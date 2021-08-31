#include <iostream>
#include <set>
using namespace std;

int a[100000+10];

int main(){
	int n, m, sum = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n;){
		int tmp = 0;
		while(i < n && tmp+a[i] <= m){
			tmp += a[i];
			i++;
		}
		sum++;		
	}
	cout << sum;
	
	return 0;
}
