#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;
#define LOCAL 0
struct tim{
	int s;
	int e;
	int flag;
}t[205];

bool f(const tim x,const tim y){
	if(x.s < y.s){
		return true;
	}else if(x.s > y.s){
		return false;
	}else{
		if(x.e > y.e){
			return true;
		}else{
			return false;
		}
	}
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int m;
		cin >> m;
		for(int j = 0;j < m;j++){
			int a,b;
			cin >> a >> b;
			if(a > b){
				swap(a,b);
			}
			t[j].s = a;
			t[j].e = b;
			t[j].flag = 0;
			if(t[j].s%2 == 0)
				t[j].s--;
			if(t[j].e%2 == 1)
				t[j].e++;
		}
		sort(t,t+m,f);
		int sum = 0;
		for(int j = 0;j < m;j++){
//			cout << "#" << t[j].s << " " << t[j].e << endl;
			if(t[j].flag == 0){
				t[j].flag = 1;
				int tmp = t[j].e;
				for(int k = j+1;k < m;k++){
					if(t[k].flag == 0 && t[k].s > tmp){
						t[k].flag = 1;
						tmp = t[k].e;
					}
				}
				sum++;
			}
		}
		cout << sum*10 << endl; 
	}
	
	return 0;
}
