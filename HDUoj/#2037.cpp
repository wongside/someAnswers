#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

struct tim{
	int s;
	int e;
}t[105];

bool f(tim x, tim y){
	if(x.e < y.e){
		return true;
	}else if(x.e > y.e){
		return false;
	}else{
		if(x.s <= y.s){
			return false;
		}else{
			return true;
		}
	}	
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
	cout << "#########################"<< endl;
#endif
	int n;
	while((cin >> n) && n != 0){
		for(int i = 0;i < n;i++){
			cin >> t[i].s >> t[i].e;
		}
		sort(t,t+n,f);
		int sum = 1;
		int tmp = t[0].e;
		for(int i = 1;i < n;i++){
			if(t[i].s >= tmp){
				sum++;
				tmp = t[i].e;
			}
//			cout << t[i].s << "  " << t[i].e << endl; 
		} 
		cout << sum << endl;	 
	}
	
	return 0;
}
