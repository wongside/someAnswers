#include <iostream>
#include <algorithm>
using namespace std;

//定义结构体 
struct P{
	int num;			//编号 
	string val;			//票数 
}pa[25];				//存储所有数据的数组 

//排序的比较函数 
int f(P a, P b){
	//定义变量并赋值 
	string s1 = a.val;
	string s2 = b.val;
	//字符串相等时，从最高位到最低位判断数的大小 
	if(s1.length() == s2.length()){
		for(unsigned int i = 0; i < s1.length(); i++){
			//最高位越大，数越大 
			if(s1[i] > s2[i]){
				return 1;
			}else if(s1[i] < s2[i]){
				return 0;
			}
			//相等情况不用处理
		}
	}
	//数字位数越多，数字越大 
	return s1.length() > s2.length();
}

int main(){
	int n;
	//输入数据 
	cin >> n;
	for(int i = 1; i <= n; i++){
		pa[i].num = i;
		cin >> pa[i].val;
	}
	//使用f函数排序 
	sort(pa+1,pa+n+1,f);
	//输出结果 
	cout << pa[1].num << endl;
	cout << pa[1].val << endl;
	
	return 0;
}
