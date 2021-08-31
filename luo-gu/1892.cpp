#include <iostream>
using namespace std;

const int maxn = 1005;

int tab[maxn*2];

int find(int x){
	int t = x;
	while(tab[t] != t){
		t = tab[t];
	}
	int i = x, j;
	while(i != t){
		j = tab[i];
		tab[i] = t;
		i = j;
	}
	return t;
}

void join(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		tab[fx] = fy;
	}
}


int main(){
	
	int n, m, x, y;
	char ch;
	cin >> n >> m;
	for(int i = 1; i <= 2*n; i++){
		tab[i] = i;
	} 
	for(int i = 0; i < m; i++){
		cin >> ch >> x >> y;
		if(ch == 'F'){
			join(x, y);
		}else{
			join(x+n, y);
			join(y+n, x);
		}		
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(tab[i] == i){
			ans++;
		}
	}
	cout << ans;
	
	return 0;
} 
