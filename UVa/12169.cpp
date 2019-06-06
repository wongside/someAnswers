#include <cstdio>

const int maxv = 205;

long long tab[maxv];


void exgcd(long long a, long long b,long long & d, long long & x, long long & y){
	if(b == 0){
		x = 1;
		y = 0;
		d = a;
	}else{
		exgcd(b, a%b, d, y, x);
		y -= x*(a/b);
	}	
}

int main(){
	
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= 2*t; i += 2){
		scanf("%lld", &tab[i]);
	}

	
	for(long long a = 0; a < 10001; a++){
		
		long long x, y, c, d;
		exgcd(a+1, -10001, d, x, y);
		c = tab[3] - a * a * tab[1];
		if(c % d == 0){
			long long b = x * c / d;
			b %= 10001;
			int flag = 1;
			for(int i = 2; i <= 2*t; i++){
				if(i % 2 == 0){
					tab[i] = (a * tab[i-1] + b) % 10001;
				}else if((a * tab[i-1] + b) % 10001 != tab[i]){
					flag = 0;	
					break;
				}				
			}

			if(flag == 1){
				for(int i = 2; i <= 2*t; i += 2){
					printf("%lld\n", tab[i]);
				}
				return 0;				
			}			
		}			
	}
	
	return 0;
} 
