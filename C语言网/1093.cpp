#include <iostream>
using namespace std;

char buf[105];

int main(){
	int i = 100;
	cin.getline(buf, 100);
	while(!isgraph(buf[i])){
		i--;
	}
	for(; i >= 0 ; i--){
		cout << buf[i];
	}
	return 0;
}
