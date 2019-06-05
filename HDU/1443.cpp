#include <iostream>
using namespace std;

//存储k值所对应的m值，由于表中数据固定，所以事先打表 
int tab[15] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,0};

//计算表中的数据函数 
void create(void){
	for(int k = 1; k < 14; k++){		//循环k，寻找k所对应的m值 
		for(int m = k/2 + k + 1;; m++){	//循环m，m的初值可以为k+1，加上k/2进一步优化 
			int sum = 2 * k;			//目前还存在的人数 
			int now = 0;				//当前要删除的人 
			for(int i = 0; i < k; i++){	//删除K次人 
				now += m;				//往后数m个人 
				now %= sum;				//数m个人时，循环 
				if(now == 0){			//如果当前的人是最后一个（模sum为0） 
					now = sum;			//让now为最后一个人 
				}
				if(now > k){			//若为坏人 
					now--;				//删除人后，当前位置也要减小 
					sum--;				//删除人后，总人数减少 
				}
			} 
			if(sum == k){				//若删除k次人后，还剩k个（好）人 
				tab[k] = m;				//记录下k对应的m值 
				break;					//跳出m的循环 
			}
		}
	}
}

int main(){

//为节约时间，事先打表，存在程序里 
//	create();							//调用打表函数 
//	for(int i = 0; i < 15; i++){		//循环 
//		cout << tab[i] << endl;			//输出每一个k值 
//	}

	int k;								//输入变量k 
	while(cin >> k && k){				//有输入，并且输入不为0 
		cout << tab[k] << endl;			//输出对应的m值 
	}
	
	return 0;
} 
