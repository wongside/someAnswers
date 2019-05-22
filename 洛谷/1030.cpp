#include <iostream>
#include <cstring>
using namespace std;

string pre, mid, pos;

void print(int mi, int mj, int pi, int pj){
	if(mj <= mi){
		return;
	}
	if(mj == mi + 1){
		cout << mid[mi];
		return;
	}
	
	int p = mi;
	while(mid[p++] != pos[pj-1]);
	
	print(p-1, p, pj-1, pj);
	print(mi, p-1, pi, pi + p-1-mi);	
	print(p, mj, pi + p-1-mi, pj-1);
}

int main(){
	
	cin >> mid >> pos;
	
	print(0, mid.length(), 0, pos.length());
	
	return 0;
}
