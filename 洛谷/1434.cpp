#include <iostream>
using namespace std;

int tab[105][105];
int ans[105][105];
int r, c;

int dfs(int x, int y){
	if(x <= 0 || x > r || y <= 0 || y > c){
		return 0;
	}
	if(ans[x][y] != 1){
		return ans[x][y];
	}
	if(tab[x-1][y] < tab[x][y])
		ans[x][y] = max(ans[x][y], dfs(x-1, y)+1);
	
	if(tab[x+1][y] < tab[x][y])
		ans[x][y] = max(ans[x][y], dfs(x+1, y)+1);
		
	if(tab[x][y-1] < tab[x][y])
		ans[x][y] = max(ans[x][y], dfs(x, y-1)+1);
		
	if(tab[x][y+1] < tab[x][y])	
		ans[x][y] = max(ans[x][y], dfs(x, y+1)+1);
	return ans[x][y];
}

int main(){

	cin >> r >> c;
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin >> tab[i][j];
			ans[i][j] = 1;
		}
	}

	int maxnum = 0;
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			maxnum = max(maxnum, dfs(i, j));
		}	
	}
	cout << maxnum;

  return 0;
}
