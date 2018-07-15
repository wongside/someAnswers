#include <iostream>
using namespace std;
#define LOCAL 1


int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		 
	} 
	
	return 0;
}
