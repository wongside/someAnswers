#include <iostream>
#include <cstring>			//memeset
using namespace std;

int tab[60];				//����ռ� 
int a, b, n;

//����f(n)��ֵ 
int f(int x){				//���е�ֵ������Ϊ49 
	x = x % 49;				//�Ƚ�xȡģ 
	if(x == 0){				//��ȡģ��Ϊ0 
		x = 49;				//���Ӧ��Ϊ49 
	}
	if(tab[x] == -1){		//��x��û�м���� 
		if(x <= 2){			//��Ŀ�е����� 
			tab[x] = 1;		 
		}else{
			tab[x] = (a * f(x-1) + b * f(x-2)) % 7;
		}		
	}
	return tab[x];
}

int main(){
	
	while(cin >> a >> b >> n){
		if(a == 0 && b == 0 && n == 0){		//�ж��Ƿ����
			break;
		}
		memset(tab, -1, 60 * sizeof(int));	//�������ʼ�� 
		cout << f(n) << endl;
	}
	
	return 0;
}
