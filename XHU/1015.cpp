#include <iostream>
using namespace std;


int main(){
	
	int n, tmp;
	while(cin >> n && n != 0){
		int nowFloor = 0;
		long long sumTime = 0;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			if(tmp > nowFloor){
				sumTime += (tmp - nowFloor) * 6 + 5;
			}else{
				sumTime += (nowFloor - tmp) * 4 + 5;
			}
			nowFloor = tmp;
		}
		cout << sumTime << endl;
	}
	
	return 0;
}
