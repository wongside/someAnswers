#include <iostream>
#include <math.h>
using namespace std;
#define LOCAL 0
/*
*  π”√…∏∑®RE,Œ¥AC
* 
*/
int isPrime(int x){
	int tmp = (int)sqrt(x * 1.0);
	for(int i = 2;i <= tmp;i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n;
	while(cin>>n){
		int count = 0; 
		int tmp;
		for(int i = 0;i < n;i++){
			scanf("%d",&tmp);
			if(isPrime(tmp)){
				count++;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}
