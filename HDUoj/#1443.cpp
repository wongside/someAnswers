#include <iostream>
using namespace std;

//�洢kֵ����Ӧ��mֵ�����ڱ������ݹ̶����������ȴ�� 
int tab[15] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,0};

//������е����ݺ��� 
void create(void){
	for(int k = 1; k < 14; k++){		//ѭ��k��Ѱ��k����Ӧ��mֵ 
		for(int m = k/2 + k + 1;; m++){	//ѭ��m��m�ĳ�ֵ����Ϊk+1������k/2��һ���Ż� 
			int sum = 2 * k;			//Ŀǰ�����ڵ����� 
			int now = 0;				//��ǰҪɾ������ 
			for(int i = 0; i < k; i++){	//ɾ��K���� 
				now += m;				//������m���� 
				now %= sum;				//��m����ʱ��ѭ�� 
				if(now == 0){			//�����ǰ���������һ����ģsumΪ0�� 
					now = sum;			//��nowΪ���һ���� 
				}
				if(now > k){			//��Ϊ���� 
					now--;				//ɾ���˺󣬵�ǰλ��ҲҪ��С 
					sum--;				//ɾ���˺����������� 
				}
			} 
			if(sum == k){				//��ɾ��k���˺󣬻�ʣk�����ã��� 
				tab[k] = m;				//��¼��k��Ӧ��mֵ 
				break;					//����m��ѭ�� 
			}
		}
	}
}

int main(){

//Ϊ��Լʱ�䣬���ȴ�������ڳ����� 
//	create();							//���ô������ 
//	for(int i = 0; i < 15; i++){		//ѭ�� 
//		cout << tab[i] << endl;			//���ÿһ��kֵ 
//	}

	int k;								//�������k 
	while(cin >> k && k){				//�����룬�������벻Ϊ0 
		cout << tab[k] << endl;			//�����Ӧ��mֵ 
	}
	
	return 0;
} 