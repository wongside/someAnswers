#include <iostream>
#include <algorithm>
using namespace std;


struct P{
	int num;
	int sco;
	int str;
};


P p[200000+10];
P t[200000+10];


int f(P a, P b){
	if(a.sco == b.sco){
		return a.num < b.num;
	}
	return a.sco > b.sco;
}

int value(int i, int c){
	if(f(p[2*i - 1],p[2*i]) == c){
		t[i].sco = p[2*i - 1].sco;
	}else{
		t[i].sco = p[2*i].sco;
	}
}

int merge(int n){
	for(int i = 1; i <= n; i++){
		t[i].num = p[i].num;
		t[i].sco = value(i,1);
	}			
	
	for(int i = n + 1; i <= 2*n; i++){
		t[i].sco = value(i-n,0);		
	}
	
	int lag = 1;
	int sml = n + 1;
	for(int i = 1; i <= 2*n;){
		while(lag <= n && t[lag].sco > t[sml].sco){
			p[i++] = t[lag++];
		}
		while(sml <= 2*n && t[sml].sco > t[lag].sco){
			p[i++] = t[sml++];
		}
	}
	
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
//	cout << p[1].sco << endl;
	for(int i = 0; i < r; i++){
		for(int j = 1; j <= n; j++){
			if(p[j*2].str > p[j*2-1].str){
				p[j*2].sco++;
			}else{
				p[j*2-1].sco++;
			}
		}
		
		merge(n);
			
	}
	cout << "***" << endl;
	cout << p[q].num;
	
	return 0;
} 
