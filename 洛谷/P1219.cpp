#include <iostream>
using namespace std;

struct Point{
	int x;
	int y;
};

int N = 0;			//要放的皇后的个数 
int num = 0;		//保存已经放下的皇后的数量 
int ans = 0;		//保存已经找到的答案种数 
Point q[14];		//保存已经放下的皇后的位置

//判断该位置能不能放皇后 
int check(int x, int y){
	//遍历已经放下的每一个皇后，计算是否冲突 
	for(int i = 1; i <= num; i++){
		//与第i个皇后同行的 
		if(x == q[i].x){
			return 0;
		}
		//与第i个皇后同列的 
		if(y == q[i].y){
			return 0;
		}
		//与第i个皇后同斜线的 	
		if(x + y == q[i].x + q[i].y){
			return 0;
		}
		//与第i个皇后同反斜线的 
		if(x - y == q[i].x - q[i].y){
			return 0;
		}
	}
	return 1;	
}

void dfs(int x){
	//如果已经考虑完每一行 
	if(x > N){
		//并且已经放下了N个皇后 
		if(num == N){
			ans++;
			//输出前三种解 
			if(ans <= 3){
				for(int i = 1; i <= N; i++){
					cout << q[i].y << " ";
				}
				cout << endl;
			}
		}
		return;
	}
	//遍历每一行的每一个位置 
	for(int y = 1; y <= N; y++){
		//如果能够放下皇后 
		if(check(x,y) == 1){
			//已经放下的皇后数增加1 
			num++;
			//记下刚刚放下皇后的位置 
			q[num].x = x;
			q[num].y = y;
			//搜索下一行 
			dfs(x+1);
			//把放下的皇后的数目减1
			//相当于拿起当前位置的皇后，继续考虑该行的下一个位置 
			num--;
		}
	}
}


int main(){
	cin >> N;
	dfs(1);
	cout << ans;
}
