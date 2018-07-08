#include <iostream>
#include <map>
using namespace std;
#define LOCAL 0

//返回小于n且与n互质的数的个数 
int euler(int n){ 
	int ans = n;
	int tmp = n;
 	for(int i = 2; i*i <= tmp; i++){
		if(tmp%i == 0){
			ans = ans / i * (i - 1); 
			while(tmp % i == 0){
				tmp /= i;			 
			} 
		}
	}
	if(tmp>1) {
		ans = ans / tmp * (tmp-1);
	}
	return ans;
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		cout << euler(t) << endl;
	}
		
	return 0;
}
