#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

int tim[101];
int val[101];
int f[1001];


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
		for(int v = t; v >= tim[i]; v--){
			
			if(f[v - tim[i]] + val[i] > f[v]){
//				cout << f[v] << endl;
				f[v] = f[v - tim[i]] + val[i];
			}
				
		}
	}
	cout << f[t];
	
	return 0;
}
