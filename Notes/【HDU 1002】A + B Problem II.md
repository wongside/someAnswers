# 【HDU 1002】A + B Problem II

> ## [A + B Problem II](http://acm.hdu.edu.cn/showproblem.php?pid=1002)(题目链接)

### 思路

* 该题的思路比较简单，将字符串中的数字取出，转换为数字，相加后，转换为字符，累加在结果中

### 代码

```C++
#include <iostream>
#include <string>							//字符串头文件 
using namespace std;

//返回字符串数字相加的结果 
string add(string a, string b){				//两个加数 
	int tmp = 0, i;							//tmp记录中间值，i表示当前位置 
	string sum;								//最后的结果 
	int la = a.length();					//a的长度 
	int lb = b.length();					//b的长度 
	//将位数相同的部分相加	
	for(i = 1; i <= min(la, lb); i++){		 
		tmp += a[la-i] + b[lb-i]-'0'-'0';	//计算两位相加的值 
		char ch = (tmp % 10) + '0';			//将个位转换为字符 
		sum = ch + sum;						//将字符加在结果的前面 
		tmp /= 10;							//去掉个位 
	}
	if(la > lb){
		sum = a.substr(0,la-lb) + sum;		//将长的数字剩下的部分加在Sum上 
	}else{
		sum = b.substr(0,lb-la) + sum;
	}
	int maxNum = max(la, lb);				//最长的作为循环条件 
	for(;i <= maxNum && tmp != 0; i++){		//tmp中为0就不必计算了 
		tmp += sum[maxNum-i] - '0';			//计算上次和当前位置的和 
		char ch = (tmp % 10) + '0';			//转换为字符 
		sum[maxNum-i] = ch;					//更新当前位置的值 
		tmp /= 10;							//去掉个位 
	}
	if(tmp != 0){							//若tmp最后还有值 
		char ch = tmp + '0';				//转换为字符 
		sum = ch + sum;						//加在sum的最前面 
	}
	return sum;								//返回计算的结果 
}

int main(){

	int t;									//题目中的t（样例数） 
	string s1, s2;							//两个加数 
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s1 >> s2;
		cout << "Case " << i + 1 << ":" << endl;
		cout << s1 << " + " << s2 << " = " << add(s1, s2) << endl;
		if(i + 1 != t){						//不是最后一行 
			cout << endl;					//输出一个空行 
		}
	}

	return 0;
}
```

### 总结

* add函数中的tmp，最开始没有初始化，在本地运行没有问题，当提交到oj上去后就错误。