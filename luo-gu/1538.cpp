#include <iostream>
#include <string> 
using namespace std;

/*��СΪ2ʱ��ÿ�����ֵĿ���Ϊ4����Ϊ7������2�ı�ʾ����(.��ʾ�ո�) 
	.--.
	...|
	...|
	.--.
	|...
	|...
	.--.
 *���Ե���СΪ1ʱ������Ϊ3����Ϊ5(#Ϊ����֮��ķָ���)
 *   0   1   2   3   4   5   6   7   8   9
 * # - #   # - # - #   # - # - # - # - # - #
 * #| |#  |#  |#  |#| |#|  #|  #  |#| |#| |#
 * #   #   # - # - # - # - # - #   # - # - #
 * #| |#  |#|  #  |#  |#  |#| |#  |#| |#  |#
 * # - #   # - # - #   # - # - #   # - # - #
*/
string tab[6] = {"",/*0   1   2   3   4   5   6   7   8   9*/
					" -       -   -       -   -   -   -   -  ",	//1
					"| |   |   |   | | | |   |     | | | | | ",	//2
					"         -   -   -   -   -       -   -  ",	//3
					"| |   | |     |   |   | | |   | | |   | ",	//4
					" -       -   -       -   -       -   -  "	//5
				};

int main(){
	int k, len, t1, t2;
	string num;
	
	cin >> k >> num;					//�������� 
	len = num.length();					//�ַ����ĳ��� 
	for(int x = 1; x < 6; x++){			//ѭ�����5�� 
		if(x%2 == 0){					//��Ϊ��2�л��ߵ�4�� 
			t1 = k;						//���е�ѭ��������Ϊk�� 
		}else{							//���� 
			t1 = 1;						//ѭ������Ϊ1�� 
		}
		for(int i = 0; i < t1; i++){	//ѭ��t1�� 
			for(int pos = 0; pos < len; pos++){			//ѭ�����ÿ���ַ� 
				for(int y = 0; y < 4; y++){				//��С�ַ�����Ϊ4 
					int tmp = (num[pos] - '0') * 4 + y;	//������tab�е�λ��			
					if(tmp%4 == 1){						//��Ϊ�ַ��ĵ�2��λ�� 
						t2 = k;							//����ѭ��k�� 
					}else{								//���� 
						t2 = 1;							//ѭ��1�� 
					}
					for(int j = 0; j < t2; j++){		//ѭ��t2�� 
						cout << tab[x][tmp];			//����������ַ� 
					}
				}
			}
			cout << endl;								//������� 
		}
	}
	
	
	return 0;
}