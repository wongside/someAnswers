#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, t, tmp, ans = 1;
	cin >> n;
	int x = 0, y = 0;
	cin >> t;
	for(int i = 1; i < n; i++){
		cin >> tmp;
		if(t < 0){
			if(abs(tmp) > abs(t) && tmp < 0){
				y++;
			}
			if(abs(tmp) < abs(t) && tmp > 0){
				x++;
			}
		}else{
			if(abs(tmp) > abs(t) && tmp < 0){
				x++;
			}
			if(abs(tmp) < abs(t) && tmp > 0){
				y++;
			}
		}
	}
	if(x > 0){
		ans += x;
		ans += y;
	}
	cout << ans;
	
	return 0;
} 
