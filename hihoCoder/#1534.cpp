#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define LOCAL 0

map<long long, int> m;
long long s[100010];	//存储前缀和 
int tab[100010];		//存储数组 


int main(){ 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> tab[i];
		s[i] = s[i-1] + tab[i];	// 计算前缀和 
		if(i < n)
			m[s[i]]++;			// 统计前缀和相同的个数 
	}
	long long s3 = 0;
	for(int q = n; q > 2;q--){	//枚举最后一段数组的值 
		s3 += tab[q];			//最后一段数组的和 
		m[s[q-1]]--;			//前缀和的相同的数量减少 
		for(long long s1 = s3-1;s1 <= s3 + 1;s1++){
			long long s2 = s[n] - s1 - s3;//计算中间一段数组的值 
			if(abs(s2 - s1) <= 1 && abs(s3 - s1) <= 1 && abs(s2 - s3) <= 1){
				ans += m[s1];//满足条件则累加结果 
			}
		}
	}
	cout << ans << endl;
	return 0;
}
