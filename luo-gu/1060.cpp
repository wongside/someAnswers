#include <iostream>
using namespace std;
#define LOCAL 0


int v[30];
int p[30];
int f[30001];

int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){		
		cin >> v[i] >> p[i];		
	}
	for(int i = 0; i < m; i++){
		for(int j = n; j >= v[i]; j--){
			if(f[j - v[i]] + v[i]*p[i] > f[j]){
				f[j] = f[j - v[i]] + v[i]*p[i];
			}
		}
	}
	cout << f[n] << endl;
	
	
	
	return 0;
}
