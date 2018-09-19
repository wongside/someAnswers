#include <iostream>
using namespace std;

//求最大公约数 
long long gcd(long long a, long long b){
	long long tmp = a % b;
	if(tmp == 0){
		return b;
	}
	return gcd(b, tmp);
}
 
//求最小公倍数 
long long lcm(long long a, long long b){
	return (a * b) / gcd(a, b);
}

int main(){
	char tmp;
	long long n, t, a1, b1, a2, b2, c, d;
	cin >> n;
	
	while(n--){
		cin >> a1 >> tmp >> b1 >> a2 >> tmp >> b2;  
		c = lcm(a1*b2, b1*a2);		//计算分子 
		t = gcd(c, b1 * b2);		//计算分子分母最大公约数 
		d = b1 * b2 / t;			//分母约分 
		c /= t;						//分子约分 
		if(d == 1){					//判断分母是否为 1 
			cout << c << endl;
		}else{
			cout << c << tmp << d << endl;
		}
	}
		
	
	return 0;
} 
