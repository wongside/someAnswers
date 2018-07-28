#include <iostream>
using namespace std;

//0��ʾ�����ߣ�1��ʾ�ϰ���-1��ʾ�Ѿ��߹� 
int map[10][10];		//�����Թ����ϰ����Ѿ��߹������� 
int n,m,t;				//����Ŀ������ı���һ�� 
int sx,sy,fx,fy;		//ͬ�� 
int ans = 0;			//�������� 

//����x��y���� 
void dfs(int x, int y){
	//�������յ㣬����������1���˳����� 
	if(x == fx && y == fy){
		ans++;
		return;
	}
	//��λ�õ��Ϸ��ܲ����� 
	//&&Ϊ��·���������Χ�ж���ǰ 
	if(x-1 >= 1 && map[x-1][y] == 0){
		//���Ϊ�Ѿ��߹� 
		map[x-1][y] = -1;
		//�������Ϸ�λ�� 
		dfs(x-1,y);
		//ȡ����� 
		map[x-1][y] = 0;
	}
	//�жϸ�λ�õ��·� 
	if(x+1 <= n && map[x+1][y] == 0){
		map[x+1][y] = -1;
		dfs(x+1,y);
		map[x+1][y] = 0;
	}
	//�жϸ�λ�õ��� 
	if(y-1 >= 1 && map[x][y-1] == 0){
		map[x][y-1] = -1;
		dfs(x,y-1);
		map[x][y-1] = 0;
	}
	//�жϸ�λ�õ��ҷ� 
	if(y+1 <= m && map[x][y+1] == 0){
		map[x][y+1] = -1;
		dfs(x,y+1);
		map[x][y+1] = 0;
	}
}


int main(){
	//����ĿҪ�������Ӧ��ֵ 
	cin >> n >> m >> t;
	cin >> sx >> sy;
	cin >> fx >> fy;
	for(int i = 0; i < t; i++){
		int t1,t2;
		cin >> t1 >> t2;
		map[t1][t2] = 1;
	}
	//ÿ��·�߱��뾭����ʼλ�ã���ǿ�ʼλ��
	map[sx][sy] = -1;
	//�ӿ�ʼ����ʼ���� 
	dfs(sx,sy);
	//����� 
	cout << ans;
} 
