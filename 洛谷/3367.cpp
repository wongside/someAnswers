#include <iostream>
using namespace std;

const int maxn = 10005;
int pre[maxn];

void init(void){
	for(int i = 0; i < maxn; i++){
		pre[i] = i;
	}
}

int find(int x){
	int y, t;
	y = x;
	while(x != pre[x]){
		x = pre[x];
	}
	while(y != x){
		t = pre[y];
		pre[y] = x;
		y = t;
	}
	return x;
}

void join(int x, int y){
	int t1, t2;
	t1 = find(x);
	t2 = find(y);
	if(t1 != t2){
		pre[t1] = t2;
	}
}

int main(){
	
	
	init();
	int n, m;
	cin >> n >> m;
	while(m--){
		int z, x, y;
		cin >> z >> x >> y;
		if(z == 1){
			join(x, y);			
		}else if(z == 2){
			if(find(x) == find(y)){
				cout << "Y" << endl;
			}else{
				cout << "N" << endl;
			}
		}
	}
	
	return 0;
} 
