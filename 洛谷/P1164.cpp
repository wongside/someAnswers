#include <iostream>
using namespace std;
#define LOCAL 0


int t[101];
long long f[10001];

int main(){	
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){		
		cin >> t[i];		
	}
	f[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = m; j >= t[i]; j--){
			f[j] += f[j - t[i]];
		}
	}
	cout << f[m] << endl;
		
	
	return 0;
}
