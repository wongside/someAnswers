#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//�����Լ�� 
int gcd(int a, int b){			//���˲�����a > b 
	int tmp = a % b;			//����aģb��ֵ 
	if(tmp == 0){				//��Ϊ0
		return b;				//����b 
	}
	return gcd (b, tmp);		//�ݹ���� 
}

int main(){ 
	string a, b, s;
	int n, tmp, x, y;
	cin >> n;
	while(n--){
		cin >> s;
		x = 0;
		y = 0;
		a = "";
		b = "";
		tmp = s.find('(');				//�ԣ�������ѭ�����ֺͲ�ѭ������ 
		if(tmp != -1){					//�ҵ�����Ϊѭ��С�� 
			b = s.substr(tmp+1);		//�����ѭ������ 
			b.erase(b.length()-1);		//ȥ�����ģ����� 
//			cout << s.substr(tmp+1, s.length())  << endl;
//			cout << s.substr(tmp+1, s.length()-1) << endl;
//			cout << s.substr(tmp+1, s.length()-2) << endl;
			if(tmp != 2){				//�����в�ѭ������ 
				a = s.substr(2, tmp-2);	//�������ѭ������ 
			}			
		}else{
			a = s.substr(2);			//�������ѭ������ 
		}
		//���ַ���ת��Ϊ���� 
		for(unsigned int i = 0; i < a.length(); i++){
			x *= 10;
			x += (a[i] - '0');
		}
		for(unsigned int i = 0; i < b.length(); i++){
			y *= 10;
			y += (b[i] - '0');
		}
		
		//С��ת��Ϊ���� 
		if(b.length() == 0){							//��ѭ��С����� 
			int t1 = pow(10, a.length());				
			int t2 = gcd(x, t1);
			cout << x / t2 << '/';
			cout << t1 / t2 << endl;
		}else{
			int t1 = x * pow(10, b.length()) + y - x;
			int t2 = pow(10, a.length() + b.length()) - pow(10, a.length());
			int t3 = gcd(t1, t2);
			cout << t1 / t3 << '/';
			cout << t2 / t3 << endl;
		}
		

	}
	
	
	return 0;
} 
