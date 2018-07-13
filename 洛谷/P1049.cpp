#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

int t[31];
int f[20001];


int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int v,n;
	cin >> v >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i];	
	}
	
	for(int i = 0; i < n; i++){
		for(int j = v; j >= t[i]; j--){			
			if(f[j - t[i]] + t[i] > f[j]){
				f[j] = f[j - t[i]] + t[i];
			}				
		}
	}
	cout << v - f[v];
	
	return 0;
}
