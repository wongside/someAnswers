#include <iostream>
using namespace std;

struct Point{
	int x;
	int y;
};

int N = 0;			//Ҫ�ŵĻʺ�ĸ��� 
int num = 0;		//�����Ѿ����µĻʺ������ 
int ans = 0;		//�����Ѿ��ҵ��Ĵ����� 
Point q[14];		//�����Ѿ����µĻʺ��λ��

//�жϸ�λ���ܲ��ܷŻʺ� 
int check(int x, int y){
	//�����Ѿ����µ�ÿһ���ʺ󣬼����Ƿ��ͻ 
	for(int i = 1; i <= num; i++){
		//���i���ʺ�ͬ�е� 
		if(x == q[i].x){
			return 0;
		}
		//���i���ʺ�ͬ�е� 
		if(y == q[i].y){
			return 0;
		}
		//���i���ʺ�ͬб�ߵ� 	
		if(x + y == q[i].x + q[i].y){
			return 0;
		}
		//���i���ʺ�ͬ��б�ߵ� 
		if(x - y == q[i].x - q[i].y){
			return 0;
		}
	}
	return 1;	
}

void dfs(int x){
	//����Ѿ�������ÿһ�� 
	if(x > N){
		//�����Ѿ�������N���ʺ� 
		if(num == N){
			ans++;
			//���ǰ���ֽ� 
			if(ans <= 3){
				for(int i = 1; i <= N; i++){
					cout << q[i].y << " ";
				}
				cout << endl;
			}
		}
		return;
	}
	//����ÿһ�е�ÿһ��λ�� 
	for(int y = 1; y <= N; y++){
		//����ܹ����»ʺ� 
		if(check(x,y) == 1){
			//�Ѿ����µĻʺ�������1 
			num++;
			//���¸ոշ��»ʺ��λ�� 
			q[num].x = x;
			q[num].y = y;
			//������һ�� 
			dfs(x+1);
			//�ѷ��µĻʺ����Ŀ��1
			//�൱������ǰλ�õĻʺ󣬼������Ǹ��е���һ��λ�� 
			num--;
		}
	}
}


int main(){
	cin >> N;
	dfs(1);
	cout << ans;
}
