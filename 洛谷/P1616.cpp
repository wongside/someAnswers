#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

int tim[10001];
int val[10001];
int f[100001];


int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int t,m;
	cin >> t >> m;
	for(int i = 0; i < m; i++){
		cin >> tim[i] >> val[i];		
	}
	
	for(int i = 0; i < m; i++){
		for(int j = tim[i]; j <= t; j++){
			
			if(f[j - tim[i]] + val[i] > f[j]){
//				cout << f[v] << endl;
				f[j] = f[j - tim[i]] + val[i];
			}				
		}
	}
	cout << f[t];
	
	return 0;
}
