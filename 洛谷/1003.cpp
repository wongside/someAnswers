#include <iostream>
using namespace std;

int t[10000+10][4];

int main(){
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			cin >> t[i][j];
		}
	}
	int x,y;
	cin >> x >> y;	
	int ans = -1;
	for(int i = n-1; i >= 0; i--){
		int x1 = t[i][0];
		int y1 = t[i][1];
		int x2 = t[i][0] + t[i][2];
		int y2 = t[i][1] + t[i][3];
		if(x1 <= x && x <= x2 && y1 <= y && y <= y2){
			ans = i + 1;
			break;
		}
	}
	cout << ans;
	
	return 0;
} 
