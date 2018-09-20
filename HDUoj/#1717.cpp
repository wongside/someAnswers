#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//求最大公约数 
int gcd(int a, int b){			//传人参数，a > b 
	int tmp = a % b;			//计算a模b的值 
	if(tmp == 0){				//若为0
		return b;				//返回b 
	}
	return gcd (b, tmp);		//递归调用 
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
		tmp = s.find('(');				//以（来分离循环部分和不循环部分 
		if(tmp != -1){					//找到（，为循环小数 
			b = s.substr(tmp+1);		//分离出循环部分 
			b.erase(b.length()-1);		//去掉最后的）符号 
//			cout << s.substr(tmp+1, s.length())  << endl;
//			cout << s.substr(tmp+1, s.length()-1) << endl;
//			cout << s.substr(tmp+1, s.length()-2) << endl;
			if(tmp != 2){				//若数有不循环部分 
				a = s.substr(2, tmp-2);	//分离出不循环部分 
			}			
		}else{
			a = s.substr(2);			//分离出不循环部分 
		}
		//将字符串转换为数字 
		for(unsigned int i = 0; i < a.length(); i++){
			x *= 10;
			x += (a[i] - '0');
		}
		for(unsigned int i = 0; i < b.length(); i++){
			y *= 10;
			y += (b[i] - '0');
		}
		
		//小数转换为分数 
		if(b.length() == 0){							//不循环小数情况 
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
