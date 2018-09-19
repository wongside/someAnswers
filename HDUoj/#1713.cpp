#include <iostream>
using namespace std;

//�����Լ�� 
long long gcd(long long a, long long b){
	long long tmp = a % b;
	if(tmp == 0){
		return b;
	}
	return gcd(b, tmp);
}
 
//����С������ 
long long lcm(long long a, long long b){
	return (a * b) / gcd(a, b);
}

int main(){
	char tmp;
	long long n, t, a1, b1, a2, b2, c, d;
	cin >> n;
	
	while(n--){
		cin >> a1 >> tmp >> b1 >> a2 >> tmp >> b2;  
		c = lcm(a1*b2, b1*a2);		//������� 
		t = gcd(c, b1 * b2);		//������ӷ�ĸ���Լ�� 
		d = b1 * b2 / t;			//��ĸԼ�� 
		c /= t;						//����Լ�� 
		if(d == 1){					//�жϷ�ĸ�Ƿ�Ϊ 1 
			cout << c << endl;
		}else{
			cout << c << tmp << d << endl;
		}
	}
		
	
	return 0;
} 
