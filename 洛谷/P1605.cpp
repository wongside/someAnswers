#include <iostream>
using namespace std;

//0表示可以走，1表示障碍，-1表示已经走过 
int map[10][10];		//保存迷宫的障碍和已经走过的坐标 
int n,m,t;				//与题目中输入的变量一致 
int sx,sy,fx,fy;		//同上 
int ans = 0;			//方案总数 

//深搜x，y坐标 
void dfs(int x, int y){
	//若到达终点，方案总数加1，退出函数 
	if(x == fx && y == fy){
		ans++;
		return;
	}
	//该位置的上方能不能走 
	//&&为短路运算符，范围判断在前 
	if(x-1 >= 1 && map[x-1][y] == 0){
		//标记为已经走过 
		map[x-1][y] = -1;
		//深搜其上方位置 
		dfs(x-1,y);
		//取消标记 
		map[x-1][y] = 0;
	}
	//判断该位置的下方 
	if(x+1 <= n && map[x+1][y] == 0){
		map[x+1][y] = -1;
		dfs(x+1,y);
		map[x+1][y] = 0;
	}
	//判断该位置的左方 
	if(y-1 >= 1 && map[x][y-1] == 0){
		map[x][y-1] = -1;
		dfs(x,y-1);
		map[x][y-1] = 0;
	}
	//判断该位置的右方 
	if(y+1 <= m && map[x][y+1] == 0){
		map[x][y+1] = -1;
		dfs(x,y+1);
		map[x][y+1] = 0;
	}
}


int main(){
	//按题目要求输入对应的值 
	cin >> n >> m >> t;
	cin >> sx >> sy;
	cin >> fx >> fy;
	for(int i = 0; i < t; i++){
		int t1,t2;
		cin >> t1 >> t2;
		map[t1][t2] = 1;
	}
	//每种路线必须经过开始位置，标记开始位置
	map[sx][sy] = -1;
	//从开始处开始深搜 
	dfs(sx,sy);
	//输出答案 
	cout << ans;
} 
