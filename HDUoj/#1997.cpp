#include <iostream>
using namespace std;

//存储输入的状态，tab[i][0]表示第i个柱子上的盘子数目，后面依次为盘子的编号 
int tab[3][65];

//判断tab中的状态是不是移动n个盘子时的中间状态 
int f(int n){										//输入为盘子的数目 
	for(int i = 0; i < 3; ++i){						//分别判断三个柱子 
		if(0 == tab[i][0]){							//若该柱子没有盘子 
			continue;								//直接判断下一个柱子 
		}
		//奇数个盘子时在第奇数个柱子的最下面的盘子的编号为奇数，偶数相反 
		if((n+i) % 2 != tab[i][1] % 2){				//若不相同 
			return 0;								//直接返回false 
		}
		//每个柱子上的盘子编号应该是奇偶数交替 
		for(int j = 2; j <= tab[i][0]; ++j){		//循环柱子上的每一个盘子 
			if((tab[i][j-1]+tab[i][j]) % 2 == 0){	//若编号不是交替 
				return 0;							//直接返回false 
			}
		}		
	}
	return 1;										//条件满足，返回true 
}

int main(){
	int t, n;										//定义变量 
	cin >> t;										//输入样例数 
	while(t--){										//循环t次 
		cin >> n;									//输入盘子数目
		//输入柱子上的盘子状态				 
		for(int i = 0; i < 3; ++i){					//循环 
			cin >> tab[i][0];						//输入柱子上盘子数目 
			for(int j = 1; j <= tab[i][0]; ++j){	//循环 
				cin >> tab[i][j];					//输入柱子上的盘子编号
			}
		}
		if(f(n)){									//若返回为 1 
			cout << "true" << endl;					//输出true 
		}else{										//否则 
			cout << "false" << endl;				//输出false 
		}
	}
	
	
	return 0;
} 
