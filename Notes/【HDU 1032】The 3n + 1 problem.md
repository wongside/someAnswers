# 【HDU 1032】The 3n + 1 problem

> ## [The 3n + 1 problem](http://acm.hdu.edu.cn/showproblem.php?pid=1032)(题目链接)

### 思路

* 思路比较简单，递归加存储
  * 网上有人说，不用存储也能过（没有试）
  * 但是需要注意n的范围，否则数组会越界
  * 因为3*n+1的结果可能比3000000还要大（最开始一直没有想通）
  * 所以超出1000000的数，就不存储

* 输入的i j不一定是从小到大

### 代码

```c++
#include <iostream>
using namespace std;

//存储n对应的循环长度 
int tab[1000000+10];

//返回n对应的循环长度 
int f(int n){
	if(n == 1)						//当n为 1，递归出口 
		return 1;					//循环长度为 1 
	int tmp;						//计算出的临时变量 
	if(n > 1000000 || tab[n] == 0){	//超出表的范围或还没有计算 
		if(n % 2 == 1){				//奇数 
			tmp = f(3*n + 1) + 1;	//循环长度加 1 
		}else{						//偶数 
			tmp =  f(n / 2) + 1;	//循环长度也加 1 
		}
		if(n <= 1000000){			//在表的范围内 
			tab[n] = tmp;			//记录在表中 
		}
		return tmp;					//返回循环长度 
	}
	return tab[n];					//已经在表中时，直接返回 
}

int main(){
	
	int i, j, t1, t2;				//
	while(cin >> t1 >> t2){			//t1 t2保存输入顺序 
		if(t1 > t2){				//交换t1 t2的位置 
			i = t2;					//让 i 小于 j 
			j = t1;
		}else{
			i = t1;
			j = t2;
		}
		int max = f(j);				//max先赋值为其中的一个值 
		for(int k = i; k < j; k++){	//循环整个范围（j已经赋值给max） 
			if(f(k) > max){			 
				max = f(k);			//记录最大值 
			}
		}
		cout << t1 << " " << t2 << " " << max << endl;
	}
	
	return 0;
}
```

### 总结

* 读题目不太认真，没有看到输出的顺序跟输入要一致
* 默认i j从小到大
* 使用数组时，没有考虑到访问越界的情况