#include <iostream>
using namespace std;

//返回a，b的最大公倍数（a > b） 
int f(int a, int b){
	int tmp = a % b;	//求a模b 
	if(tmp == 0)		//若为0 
		return b;		//b为最大公倍数 
	return f(b, tmp);	//否则递归调用 
}

int main(){
	
	int p, m, n;
	cin >> p;
	while(p--){
		cin >> m >> n;
		if(f(n, m) == 1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	
	
	return 0;
} 
