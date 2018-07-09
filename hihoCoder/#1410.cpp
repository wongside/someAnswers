#include <iostream>
using namespace std;

int f(int n){
	int sum = 1;
	while(n > sum){
		sum *= 2;
	}
	if(sum == n)
		return 1;
	int t1 = f(n - sum/2);
	int t2 = f(sum - n);
	if(t1 > t2)
		return t2 + 1;	
	return t1 + 1;	
}

int main(){
	int n ;
	cin >> n;
	cout << f(n) << endl;
}
