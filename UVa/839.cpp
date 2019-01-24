#include <iostream>
using namespace std;

int result(int & w){
	int b1 = 1, b2 = 1;
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if(!w1){
		b1 = result(w1);
	}
	if(!w2){
		b2 = result(w2);
	}
	w = w1 + w2;
	return b1 && b2 && (w1*d1 == w2*d2);
}

int main(){
	int n, w;
	cin >> n;
	while(n--){
		if(result(w)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
		if(n){
			cout << endl;
		}
	}
	
	return 0;
}
