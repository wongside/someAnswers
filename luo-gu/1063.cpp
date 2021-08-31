#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;			//�ֵ䣬���ڴ洢���ʶ�Ӧ����ֵ 
int num[10], cnt = 0;		//num�洢�ӵ����з����������֣�cnt��ʾ���ָ��� 

int main()
{
	//�����ʶ�Ӧ�����ִ���map 
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["a"] = 1;
    m["both"] = 2;
    m["another"] = 1;
    m["second"] = 2;
    m["first"] = 1;
    m["third"] = 3;
    
    string str;
    for(int i = 0; i < 7; i++){						//6�����ʼ�1����� 
        cin >> str;									//�������� 
        if(m.count(str) == 1){						//���Ǳ�ʾ���ֵĵ��� 
        	num[cnt++] = (m[str] * m[str]) % 100;	//����cum����ͳ�Ƹ��� 
		}
    }
    
    sort(num, num+cnt);	//��С�����������е����� 
    
    int pos = 0;		//��¼����һλ��ʼ����0 
    //��posָ���һ������0������С��cnt��ֹԽ�磨��RE�� 
    for(; pos < cnt && num[pos] == 0; pos++);   
    for(int i = pos; i < cnt; i++){				//�Ӳ���0��λ�ÿ�ʼ��� 
    	if(i != pos && num[i] < 10){			//���ǵ�1������С��10
    		cout << 0;							//�����0  
		}
		cout << num[i];							//����ֱ�����ԭ�� 
	}
	if(pos == cnt){								//����������Ϊ0(���Ե�3) 
		cout << 0;								//��ֱ�����0 
	}
    
    return 0;
}
