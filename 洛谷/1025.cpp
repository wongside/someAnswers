#include <iostream>
using namespace std;

int n, k, ans = 0;

/*
 *last:上一次循环到的值
 *cur :当前分的个数
 *sum :当前累计的总数 
*/
void f(int last, int cur, int sum){
	if(cur == k){			//如果分的个数和需要分的个数相同，就退出 
		if(n == sum){		//如果刚刚分完，就统计一次 
			ans++;
		}
		return;
	}
	//限制数范围，防止后面分的数比前面的小，从而避免重复 
	for(int i = last; sum + i*(k-cur) <= n; i++){
		f(i, cur+1, sum+i);
	}
}

int main(){
	cin >> n >> k;
	f(1, 0, 0);
	cout << ans;

	return 0;
} 
/*最开始想到的方法是dp，但是最开始找到的状态转移方程有问题，所以没能AC， 
 *后面自己也想到了用多层for来搜索，搜索的次数用递归解决，但是循环条件
 *没有找好，导致分出来的数有重复，没有AC；看了dalao的方法，才知道了循环
 *条件，最终AC。 
*/ 
