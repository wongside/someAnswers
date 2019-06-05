#include <iostream>
using namespace std;
#define LOCAL 0

int gcd(int a,int b){
	int tmp = a % b;
	if(tmp == 0)
		return b;
	return gcd(b,tmp);
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int m,n;
	while(cin >> m >> n){
		if(m < n)
			swap(m,n);
		cout << (m * n) / gcd(m,n) << endl;
	} 
	
	return 0;
}
