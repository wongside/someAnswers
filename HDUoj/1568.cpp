#include <iostream>			//输入输出头文件 
#include <cmath>			//数学相关函数 
using namespace std;		//声明命名空间 

int tab[30];				//存储长度小于四位的数 
int size;					//长度小于四位的数的个数 

int main(){
	int n;					//输入数字 
	tab[1] = 1;				//数组初始化（存入数列的前两项）
	
	//将数的长度小于4的数计算出来 
	for(size = 2; size < 30; size++){				
		tab[size] = tab[size - 1] + tab[size - 2];	//计算数列的值 
		if(tab[size] > 9999){						//若大于四位 
			break;									//退出循环 
		}
	}
	
	while(cin >> n){					//输入数据 
		if(n < size){					//是否在表中已经计算 
			cout << tab[n] << endl;		//直接输出 
		}else{
			double sqrt5 = sqrt(5.0);	//根号5的值 
			double ans = log10(1/sqrt5) + n * log10((1+sqrt5)/2);	//计算公式 
			ans = ans - (int)ans;		//取小数部分 
			ans = pow(10, ans);			//求小数部分做指数的值 
			while(ans < 1000){			//若小于4位数 
				ans *= 10;				//扩大十倍 
			}
			cout << (int)ans << endl;	//输出结果 
		}		
	} 
	return 0;
} 
