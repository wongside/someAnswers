#include <iostream>
#include <cmath>
using namespace std;

double point[20][2];
double dis[20][20];
int vis[20];
int n;

double mindis = 0.0;

void dfs(int step, int now, double sum){
	if(sum > mindis){
		return;
	}
	if(step == n){
		mindis = min(mindis, sum);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(step+1, i, sum + dis[now][i]);
			vis[i] = 0;
		}
	}
	
}

int main(){
	
	cin >> n;
	point[0][0] = 0.0;
	point[0][1] = 0.0;
	for(int i = 1; i <= n; i++){
		cin >> point[i][0] >> point[i][1];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dis[i][j] = sqrt((point[i][0]-point[j][0])*(point[i][0]-point[j][0])
				+ (point[i][1]-point[j][1])*(point[i][1]-point[j][1]));
			mindis += dis[i][j];
		}
	}
	dfs(0, 0, 0.0);
	printf("%0.2f", mindis);
	
	
	return 0;
}
