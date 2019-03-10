#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define LOCAL 0

map<long long, int> m;
long long s[100010];	//�洢ǰ׺�� 
int tab[100010];		//�洢���� 


int main(){ 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> tab[i];
		s[i] = s[i-1] + tab[i];	// ����ǰ׺�� 
		if(i < n)
			m[s[i]]++;			// ͳ��ǰ׺����ͬ�ĸ��� 
	}
	long long s3 = 0;
	for(int q = n; q > 2;q--){	//ö�����һ�������ֵ 
		s3 += tab[q];			//���һ������ĺ� 
		m[s[q-1]]--;			//ǰ׺�͵���ͬ���������� 
		for(long long s1 = s3-1;s1 <= s3 + 1;s1++){
			long long s2 = s[n] - s1 - s3;//�����м�һ�������ֵ 
			if(abs(s2 - s1) <= 1 && abs(s3 - s1) <= 1 && abs(s2 - s3) <= 1){
				ans += m[s1];//�����������ۼӽ�� 
			}
		}
	}
	cout << ans << endl;
	return 0;
}
