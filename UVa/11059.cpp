#include <iostream>
using namespace std;

int tab[20];

int main(){
	
	int n, kase = 1;
	while(cin >> n){
		long long maxsum = -1;
		for(int i = 0; i < n; i++){
			cin >> tab[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				long long tmpsum = 1;
				for(int k = i; k <= j; k++){
					tmpsum *= tab[k];
				}
				maxsum = max(maxsum, tmpsum);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", kase++, maxsum < 0? 0: maxsum);
	}
	
	return 0;
}

/*
3
2 4 -3
5
2 5 -1 2 -1
1
-2
*/
