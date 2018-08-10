#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[20+5];

int f(string a, string b){
//	return a > b;			//有一个测试点未AC 
	return a+b > b+a;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str[i];		
	}
	
	sort(str, str+n, f);
	for(int i = 0; i < n; i++){
		cout << str[i];
	}
		
	
	return 0;
} 
