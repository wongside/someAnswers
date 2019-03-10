#include <iostream>			//�������ͷ�ļ� 
#include <cmath>			//��ѧ��غ��� 
using namespace std;		//���������ռ� 

int tab[30];				//�洢����С����λ���� 
int size;					//����С����λ�����ĸ��� 

int main(){
	int n;					//�������� 
	tab[1] = 1;				//�����ʼ�����������е�ǰ���
	
	//�����ĳ���С��4����������� 
	for(size = 2; size < 30; size++){				
		tab[size] = tab[size - 1] + tab[size - 2];	//�������е�ֵ 
		if(tab[size] > 9999){						//��������λ 
			break;									//�˳�ѭ�� 
		}
	}
	
	while(cin >> n){					//�������� 
		if(n < size){					//�Ƿ��ڱ����Ѿ����� 
			cout << tab[n] << endl;		//ֱ����� 
		}else{
			double sqrt5 = sqrt(5.0);	//����5��ֵ 
			double ans = log10(1/sqrt5) + n * log10((1+sqrt5)/2);	//���㹫ʽ 
			ans = ans - (int)ans;		//ȡС������ 
			ans = pow(10, ans);			//��С��������ָ����ֵ 
			while(ans < 1000){			//��С��4λ�� 
				ans *= 10;				//����ʮ�� 
			}
			cout << (int)ans << endl;	//������ 
		}		
	} 
	return 0;
} 
