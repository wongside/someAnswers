#include <cstring>
#include <cstdio>
#include <cmath>

const int maxv = 1e5+5;

int prime[maxv];
int endex[maxv];

void decompose(int n){
	
	memset(endex, 0, sizeof(int)*prime[0]);
	memset(prime, 0, sizeof(int)*prime[0]);
	
	int len = sqrt(n)+0.5;
	for(int i = 2; i <= len; i++){
		prime[++prime[0]] = i;
		while(n % i == 0){
			n /= i;
			endex[prime[0]]++;
		}
		if(endex[prime[0]] == 0){
			prime[0]--;
		}
	}

	if(n > 1){
		prime[++prime[0]] = n;
		endex[prime[0]] = 1;
	}
	prime[0]++;	
}

int check(int n, int k){
	int tag = 1;
	int t = n - k + 1;
	for(int i = 1; i < prime[0]; i++){					
		while(t % prime[i] == 0){
			t /= prime[i];
			endex[i]--;
		}
		while(k % prime[i] == 0){
			k /= prime[i];
			endex[i]++;
		}
		if(endex[i] > 0){
			tag = 0;
		}
	}
	return tag;
}

int ans[maxv];

int main(){
	int n, m;
	
	while(scanf("%d%d", &n, &m) == 2){
		decompose(m);
		memset(ans, 0, sizeof(int)*ans[0]);
		for(int i = 1; i < n-1; i++){
			if(check(n-1, i)){
				ans[++ans[0]] = i+1;
			}
		}
		printf("%d\n", ans[0]++);
		
		if(ans[0] > 0)
		for(int i = 1; i < ans[0]; i++){
			printf("%s%d", i==1?"":" ", ans[i]);
		}
		printf("\n");
	}
	
	
	return 0;
} 
