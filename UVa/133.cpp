#include <iostream>
using namespace std;

int queue[25];
int n, k, m;

int go(int a, int b, int c){
	while(c--){
		do{
			a = (a + b + n-1) % n+1;
		}while(queue[a] == 0);
	}
	return a;
}

int main(){
	
	while((cin >> n >> k >> m) && n+k+m != 0){
		for(int i = 1; i <= n; i++){
			queue[i] = i;
		}
		int a = n, b = 1, left = n;
		while(left){ 
			a = go(a, 1, k);
			b = go(b, -1, m);
			printf("%3d",queue[a]);
			left--;
			if(a != b){
				printf("%3d",queue[b]);
				left--;
			}
			queue[a] = queue[b] = 0;
			if(left){
				printf(",");
			}
		}
		printf("\n");
	}
	
	return 0;
}
