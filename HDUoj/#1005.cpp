#include <iostream>
#include <cstring>			//memeset
using namespace std;

int tab[60];				//缓存空间 
int a, b, n;

//返回f(n)的值 
int f(int x){				//所有的值的周期为49 
	x = x % 49;				//先将x取模 
	if(x == 0){				//当取模后为0 
		x = 49;				//则就应该为49 
	}
	if(tab[x] == -1){		//若x还没有计算的 
		if(x <= 2){			//题目中的条件 
			tab[x] = 1;		 
		}else{
			tab[x] = (a * f(x-1) + b * f(x-2)) % 7;
		}		
	}
	return tab[x];
}

int main(){
	
	while(cin >> a >> b >> n){
		if(a == 0 && b == 0 && n == 0){		//判断是否结束
			break;
		}
		memset(tab, -1, 60 * sizeof(int));	//将数组初始化 
		cout << f(n) << endl;
	}
	
	return 0;
}
