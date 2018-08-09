#include <iostream>
#include <algorithm>
using namespace std;

struct P{
	int num;
	int sco;
	int str;
};

P p[200000+10];

int f(P a, P b){
	if(a.sco == b.sco){
		return a.num < b.num;
	}
	return a.sco > b.sco;
}

int main(){
	int n,r,q;
	cin >> n >> r >> q;
	for(int i = 1; i <= 2*n; i++){
		p[i].num = i;
		cin >> p[i].sco; 
	}
	for(int i = 1; i <= 2*n; i++){	
		cin >> p[i].str; 
	}
	
	
	sort(p+1,p+2*n+1,f);
//	for(int i = 1; i <= 2*n; i++){
//		cout << i << " ";
//		cout << p[i].num << " ";
//		cout << p[i].sco << " ";
//		cout << p[i].str << " " << endl;
//	}
	for(int i = 0; i < r; i++){
		for(int i = 1; i <= n; i++){
			if(p[i*2].str > p[i*2-1].str){
				p[i*2].sco++;
			}else{
				p[i*2-1].sco++;
			}
		}
		sort(p+1,p+2*n+1,f);		
	}
	cout << p[q].num;
	
	return 0;
} 
