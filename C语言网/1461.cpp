#include <iostream>
#include <string>
using namespace std;

string f(int n){
	if(n == 1){
		return "A";
	}
	return f(n-1) + char(n-1 + 'A') + f(n-1);
}

int main(){
	
	int n;
	cin >> n;
	cout << f(n);
	
	return 0;
}
