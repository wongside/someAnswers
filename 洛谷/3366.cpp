#include <iostream>
#include <algorithm>

using namespace std;

int tab[5005][5005];
struct Edge{
	int x;
	int y;
	int v;
};

Edge arr[200000];
int vis[5005];

int cmp(Edge a, Edge b){
	return a.v < b.v;
}

int find(int x){
	int t = x;
	while(vis[t] != t){
		t = vis[t];
	}
	int i = x, j;
	while(i != t){
		j = vis[i];
		vis[i] = t;
		i = j;
	}
	return t;
}

void join(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		vis[fx] = fy;
	}
}

int main(){
	for(int i = 0; i < 5005; i++){
		vis[i] = i;
	}
	int n, m, x, y, z;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		
		arr[i].x = x;
		arr[i].y = y;
		arr[i].v = z;
 	}
	sort(arr, arr+m, cmp); 
	int ans = 0;
	for(int i = 0; i < m; i++){
		
		if(find(arr[i].x) != find(arr[i].y)){
			join(arr[i].x, arr[i].y);
			ans += arr[i].v; 
		}
	}
	cout << ans;
	
	return 0;
} 
