#include <iostream>					//��������� 
#include <string>					//�ַ��� 
#include <cstdlib>					//sprintf 
using namespace std;

//�����ַ���s�����ָ� 
string f(string s){		
	int sum = 0;					//ͳ�Ƹ�λ֮�͵ı��� 
	int len = s.length();			//�ȱ�����s�ĳ��ȣ�ֱ����int�Ƚ��о��棩 
	for(int i = 0; i < len; i++){	//ѭ������ 
		sum += s[i] - '0';			//��ȥ�ַ� 0 ���õ����ֵ�ֵ 	
	}
	char tmp[100];					//����תΪ�ַ�������ʱ�洢���� 
	sprintf(tmp, "%d", sum);		//�����ִ�ӡ���ַ������� 
	if(sum < 10){					//���ۼӺ�ֻ��һλ		
		return tmp;					//ֱ�ӷ������� 
	}
	return f(tmp);					//���صݹ���ú��ֵ 
}

int main(){
	string s;
	while(cin >> s && s[0] != '0'){	//�����룬���Ҳ�Ϊ 0 
		cout << f(s) << endl;		//���ú���ֱ����� 
	}
	
	return 0;
}
