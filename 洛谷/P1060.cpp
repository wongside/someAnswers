#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define LOCAL 1

multimap<int,int> m;
int tab[30];
int cmp(int a,int b){
	return a > b;
}
int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int N,m;
	cin >> N >> m;
	for(int i = 0; i < m; i++){
		int t1,t2;
		cin >> t1 >> t2;
		
	}
	sort(tab,tab+m,cmp);
	int sum = N;
	for(int i = 0; i < m; i++){
		if(sum - tab[i] >= 0){
			sum -= tab[i];
		}
	}
	cout << N - sum << endl;
	
	
	
	return 0;
}
