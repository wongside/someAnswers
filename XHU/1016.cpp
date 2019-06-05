#include <iostream>
using namespace std;

int main(){
	
	int m, k;
	while(cin >> m >> k && m != 0){
		long long day;
		for(day = 0; m > 0; day++){
			m--;
			if(day % k == k-1){
				m++;
			}
		}
		cout << day << endl;
	}
	
	return 0;
}
