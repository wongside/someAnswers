#include <iostream>
using namespace std;

//�洢n��Ӧ��ѭ������ 
int tab[1000000+10];

//����n��Ӧ��ѭ������ 
int f(int n){
	if(n == 1)						//��nΪ 1���ݹ���� 
		return 1;					//ѭ������Ϊ 1 
	int tmp;						//���������ʱ���� 
	if(n > 1000000 || tab[n] == 0){	//������ķ�Χ��û�м��� 
		if(n % 2 == 1){				//���� 
			tmp = f(3*n + 1) + 1;	//ѭ�����ȼ� 1 
		}else{						//ż�� 
			tmp =  f(n / 2) + 1;	//ѭ������Ҳ�� 1 
		}
		if(n <= 1000000){			//�ڱ�ķ�Χ�� 
			tab[n] = tmp;			//��¼�ڱ��� 
		}
		return tmp;					//����ѭ������ 
	}
	return tab[n];					//�Ѿ��ڱ���ʱ��ֱ�ӷ��� 
}

int main(){
	
	int i, j, t1, t2;				//
	while(cin >> t1 >> t2){			//t1 t2��������˳�� 
		if(t1 > t2){				//����t1 t2��λ�� 
			i = t2;					//�� i С�� j 
			j = t1;
		}else{
			i = t1;
			j = t2;
		}
		int max = f(j);				//max�ȸ�ֵΪ���е�һ��ֵ 
		for(int k = i; k < j; k++){	//ѭ��������Χ��j�Ѿ���ֵ��max�� 
			if(f(k) > max){			 
				max = f(k);			//��¼���ֵ 
			}
		}
		cout << t1 << " " << t2 << " " << max << endl;
	}
	
	return 0;
}
