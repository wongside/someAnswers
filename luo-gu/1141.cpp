#include <iostream>
#include <string>
using namespace std;

int tab[1000+10][1000+10];
int vis[1000+10][1000+10];
int n, m, k = 1;
int ans[1000000+10];

void bfs(int x, int y){
	vis[x][y] = k;
	ans[k]++;
	if(x - 1 >= 0 && vis[x-1][y] == 0 && tab[x-1][y] + tab[x][y] == 1){
		bfs(x-1, y);
	}
	if(x + 1 < n && vis[x+1][y] == 0 && tab[x+1][y] + tab[x][y] == 1){
		bfs(x+1, y);
	}
	if(y - 1 >= 0 && vis[x][y-1] == 0 && tab[x][y-1] + tab[x][y] == 1){
		bfs(x, y-1);
	}
	if(y + 1 < n && vis[x][y+1] == 0 && tab[x][y+1] + tab[x][y] == 1){
		bfs(x, y+1);
	}
}

int main(){
	string tmp;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		for(int j = 0; j < n; j++){
			tab[i][j] = tmp[j] - '0';
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j] == 0){
				bfs(i,j);
				k++;
			}			
		}
	}
	for(int i = 0; i < m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		cout << ans[vis[t1-1][t2-1]] << endl;
	}
	
	return 0;
}  
