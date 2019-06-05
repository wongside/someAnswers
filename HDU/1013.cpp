#include <iostream>					//输入输出流 
#include <string>					//字符串 
#include <cstdlib>					//sprintf 
using namespace std;

//返回字符串s的数字根 
string f(string s){		
	int sum = 0;					//统计各位之和的变量 
	int len = s.length();			//先保存下s的长度（直接与int比较有警告） 
	for(int i = 0; i < len; i++){	//循环叠加 
		sum += s[i] - '0';			//减去字符 0 ，得到数字的值 	
	}
	char tmp[100];					//数字转为字符串的临时存储变量 
	sprintf(tmp, "%d", sum);		//将数字打印到字符数组中 
	if(sum < 10){					//若累加和只有一位		
		return tmp;					//直接返回数字 
	}
	return f(tmp);					//返回递归调用后的值 
}

int main(){
	string s;
	while(cin >> s && s[0] != '0'){	//有输入，并且不为 0 
		cout << f(s) << endl;		//调用函数直接输出 
	}
	
	return 0;
}
