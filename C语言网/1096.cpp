#include <iostream>
using namespace std;

char tab[105][105];
int n, m, cnt = 1;

int ok(int i , int j){
	if(i >= 0 && j >= 0 && i < n && j < m)
		return 1;
	return 0;
}

int f(int i, int j){
	int sum = 0;
	if(ok(i-1, j-1) && tab[i-1][j-1] == '*'){
		sum++;
	}
	if(ok(i-1, j) && tab[i-1][j] == '*'){
		sum++;
	}
	if(ok(i-1, j+1) && tab[i-1][j+1] == '*'){
		sum++;
	}
	if(ok(i, j-1) && tab[i][j-1] == '*'){
		sum++;
	}
	if(ok(i, j+1) && tab[i][j+1] == '*'){
		sum++;
	}
	if(ok(i+1, j-1) && tab[i+1][j-1] == '*'){
		sum++;
	}
	if(ok(i+1, j) && tab[i+1][j] == '*'){
		sum++;
	}
	if(ok(i+1, j+1) && tab[i+1][j+1] == '*'){
		sum++;
	}
	return sum;
}

int main(){
	
	while(cin >> n >> m && n != 0){
		for(int i = 0; i < n; i++){
			scanf("%s",tab[i]);
		}
		printf("Field #%d:\n", cnt++);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(tab[i][j] == '.'){
					cout << f(i, j);
				}else{
					cout << "*";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}
