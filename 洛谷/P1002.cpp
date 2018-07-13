#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 1
/*
 1. 被马控制的位置为-1
 2. 没有计算的位置为0
 3. 大于0的数字表示从起始点到该位置的条数
 4. 递推公式为该位置上方的路径条数加上左方的路径条数	
*/ 
//全局变量被初始化为0，路径条数可能很多，使用long long 
long long m[21][21];

int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	//马周围的8个位置 
	int no[8][2] = { {1,2},{-1,2},{1,-2},{-1,-2},
				 	 {2,1},{-2,1},{2,-1},{-2,-1}
				   }; 
	//声明输入的变量，所表示的值与输入顺序对应
	int bx,by,mx,my;
	cin >> bx >> by >> mx >> my; 
	//将马的控制范围设置为-1 
	m[mx][my] = -1;
	for(int i = 0; i < 8; i++){
		int t1 = no[i][0] + mx;
		int t2 = no[i][1] + my;
		//判断马的位置是否超出范围 
		if(0 <= t1 && t1 <= bx && 0 <= t2 && t2 <= by){
			m[t1][t2] = -1;
		}
	}
	//初始化第一个位置 
	m[0][0] = 1;
	for(int i = 0; i <= bx; i++){
		for(int j = 0; j <= by; j++){
			//如果该位置被马控制，不计算 
			if(m[i][j] == -1){
				continue;
			}
			//判断并计算该位置上方的次数 
			if(i - 1 >= 0 && m[i-1][j] != -1){
				m[i][j] +=  m[i-1][j];
			}
			//判断并计算该位置左方的次数 
			if(j - 1 >= 0 && m[i][j-1] != -1){
				m[i][j] +=  m[i][j-1];
			}
		}
	}
//输出整个二维数组	
//	for(int i = 0; i <= bx; i++){
//		for(int j = 0; j <= by; j++){
//			cout << m[i][j] << "\t";
//		}
//		cout << endl;
//	}
	cout << m[bx][by] << endl;
	return 0;
}
