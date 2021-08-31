#include <iostream>
using namespace std;

int tab[105][105];
char dir[] = "URDL";
int main(){
	
	int m, n, x, y, k;
	char s;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> tab[i][j];
		}
	}
	cin >> x >> y >> s >> k;
	for(int i = 0; i < 4; i++){
		if(s == dir[i]){
			s = i;
			break;
		}
	}
	while(k--){
		if(tab[x][y]){
			s += 1;
			s %= 4;
		}else{
			s += 3;
			s %= 4;
		}
		tab[x][y] = !tab[x][y];
		switch(s){
			case 0:
				x--;
				break;
			case 1:
				y++;
				break;
			case 2:
				x++;
				break;
			case 3:
				y--;
				break;
		}
	}
	cout << x << " " << y;
	
	
	return 0;
} 
