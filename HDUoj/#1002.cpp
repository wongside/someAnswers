#include <iostream>
#include <string>							//�ַ���ͷ�ļ� 
using namespace std;

//�����ַ���������ӵĽ�� 
string add(string a, string b){				//�������� 
	int tmp = 0, i;							//tmp��¼�м�ֵ��i��ʾ��ǰλ�� 
	string sum;								//���Ľ�� 
	int la = a.length();					//a�ĳ��� 
	int lb = b.length();					//b�ĳ��� 
	//��λ����ͬ�Ĳ������	
	for(i = 1; i <= min(la, lb); i++){		 
		tmp += a[la-i] + b[lb-i]-'0'-'0';	//������λ��ӵ�ֵ 
		char ch = (tmp % 10) + '0';			//����λת��Ϊ�ַ� 
		sum = ch + sum;						//���ַ����ڽ����ǰ�� 
		tmp /= 10;							//ȥ����λ 
	}
	if(la > lb){
		sum = a.substr(0,la-lb) + sum;		//����������ʣ�µĲ��ּ���Sum�� 
	}else{
		sum = b.substr(0,lb-la) + sum;
	}
	int maxNum = max(la, lb);				//�����Ϊѭ������ 
	for(;i <= maxNum && tmp != 0; i++){		//tmp��Ϊ0�Ͳ��ؼ����� 
		tmp += sum[maxNum-i] - '0';			//�����ϴκ͵�ǰλ�õĺ� 
		char ch = (tmp % 10) + '0';			//ת��Ϊ�ַ� 
		sum[maxNum-i] = ch;					//���µ�ǰλ�õ�ֵ 
		tmp /= 10;							//ȥ����λ 
	}
	if(tmp != 0){							//��tmp�����ֵ 
		char ch = tmp + '0';				//ת��Ϊ�ַ� 
		sum = ch + sum;						//����sum����ǰ�� 
	}
	return sum;								//���ؼ���Ľ�� 
}

int main(){

	int t;									//��Ŀ�е�t���������� 
	string s1, s2;							//�������� 
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s1 >> s2;
		cout << "Case " << i + 1 << ":" << endl;
		cout << s1 << " + " << s2 << " = " << add(s1, s2) << endl;
		if(i + 1 != t){						//�������һ�� 
			cout << endl;					//���һ������ 
		}
	}

	return 0;
}
