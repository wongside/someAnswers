#include <iostream>
#include <algorithm>
using namespace std;

int tab[15];
int ans[15];
int n, sum;

int C(int n, int m){
	if(m == 0 || n == m){
		return 1;
	}
	int s1 = 1, s2 = 1;
	for(int i = 0; i < m; i++){
		s1 *= (n - i);
	}
	for(int i = 1; i <= m; i++){
		s2 *= i;
	}
	
	return (s1 / s2);
}

int cmp (int a, int b){
	return a > b;
} 

int ok(){
	int tmp = 0;
	for(int i = 1; i <= n; i++){
		tmp += ans[i] * tab[i];
		if(tmp > sum){
			sort(ans+i, ans+n+1, cmp);
			return 0; 
		}
	}
	if(tmp < sum){
		return 0;
	}
	return 1;
}

int main(){
		
	cin >> n >> sum;
	for(int i = 1; i <= n; i++){
		tab[i] = C(n-1, i-1);
	}
	for(int i = 1; i <= n; i++){
		ans[i] = i;
	}
	
	do{
		if(ok()){
			for(int i = 1; i <= n; i++){
				cout << ans[i] << " ";
			}
			cout << endl;
			break;
		}
	}while(next_permutation(ans+1, ans+n+1));
	
	return 0;
} 
