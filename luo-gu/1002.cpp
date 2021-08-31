#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 1
/*
 1. ������Ƶ�λ��Ϊ-1
 2. û�м����λ��Ϊ0
 3. ����0�����ֱ�ʾ����ʼ�㵽��λ�õ�����
 4. ���ƹ�ʽΪ��λ���Ϸ���·�����������󷽵�·������	
*/ 
//ȫ�ֱ�������ʼ��Ϊ0��·���������ܺܶ࣬ʹ��long long 
long long m[21][21];

int main(){
	//�ļ��ض��� 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	//����Χ��8��λ�� 
	int no[8][2] = { {1,2},{-1,2},{1,-2},{-1,-2},
				 	 {2,1},{-2,1},{2,-1},{-2,-1}
				   }; 
	//��������ı���������ʾ��ֵ������˳���Ӧ
	int bx,by,mx,my;
	cin >> bx >> by >> mx >> my; 
	//����Ŀ��Ʒ�Χ����Ϊ-1 
	m[mx][my] = -1;
	for(int i = 0; i < 8; i++){
		int t1 = no[i][0] + mx;
		int t2 = no[i][1] + my;
		//�ж����λ���Ƿ񳬳���Χ 
		if(0 <= t1 && t1 <= bx && 0 <= t2 && t2 <= by){
			m[t1][t2] = -1;
		}
	}
	//��ʼ����һ��λ�� 
	m[0][0] = 1;
	for(int i = 0; i <= bx; i++){
		for(int j = 0; j <= by; j++){
			//�����λ�ñ�����ƣ������� 
			if(m[i][j] == -1){
				continue;
			}
			//�жϲ������λ���Ϸ��Ĵ��� 
			if(i - 1 >= 0 && m[i-1][j] != -1){
				m[i][j] +=  m[i-1][j];
			}
			//�жϲ������λ���󷽵Ĵ��� 
			if(j - 1 >= 0 && m[i][j-1] != -1){
				m[i][j] +=  m[i][j-1];
			}
		}
	}
//���������ά����	
//	for(int i = 0; i <= bx; i++){
//		for(int j = 0; j <= by; j++){
//			cout << m[i][j] << "\t";
//		}
//		cout << endl;
//	}
	cout << m[bx][by] << endl;
	return 0;
}
