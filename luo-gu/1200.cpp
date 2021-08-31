#include <iostream>
#include <string>
using namespace std;


int main(){
	
	int sum1 = 1, sum2 = 1;
	string s1,s2;
	cin >> s1 >> s2;
	for(unsigned int i = 0; i < s1.length(); i++){
		int tmp = s1[i] - 'A' + 1;
		sum1 *= tmp;
		sum1 %= 47;
	}
	for(unsigned int i = 0; i < s2.length(); i++){
		int tmp = s2[i] - 'A' + 1;
		sum2 *= tmp;
		sum2 %= 47;
	}
	if(sum1 == sum2){
		cout << "GO";
	}else{
		cout << "STAY";
	}
	
	return 0;
}
