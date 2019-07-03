#include <iostream>
#include <algorithm>
using namespace std;

struct Cell{
	int r, c;
	
	Cell(){
	}
	
	Cell(int a, int b){
		r = a;
		c = b;
	}
};

int r, c, cnt = 0;
Cell tab[100][100];
int arr[100];


void del(int x, char ch){
	if(ch == 'R'){
		for(int i = x+1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				tab[i-1][j] = tab[i][j];
			}
		}
		for(int j = 1; j <= c; j++){
			tab[r][j] = Cell(0, 0);
		}
		r--;
	}else{
		for(int i = x+1; i <= c; i++){
			for(int j = 1; j <= r; j++){
				tab[j][i-1] = tab[j][i];
			}
		}
		for(int j = 1; j <= r; j++){
			tab[j][c] = Cell(0, 0);
		}
		c--;
	}
	
}

void ins(int x, char ch){
	if(ch == 'R'){
		for(int i = r; i >= x; i--){
			for(int j = 1; j <= c; j++){
				tab[i+1][j] = tab[i][j];
			}
		}
		for(int j = 1; j <= c; j++){
			tab[x][j] = Cell(0, 0);
		}
		r++;
	}else{
		for(int i = c; i >= x; i--){
			for(int j = 1; j <= r; j++){
				tab[j][i+1] = tab[j][i];
			}
		}
		for(int j = 1; j <= r; j++){
			tab[j][x] = Cell(0, 0);
		}
		c++;
	}
}

void exc(int r1, int c1, int r2, int c2){
	Cell tmp = tab[r1][c1];
	tab[r1][c1] = tab[r2][c2];
	tab[r2][c2] = tmp;
}

bool sch(int r1, int c1, int & r2, int & c2){
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			if(tab[i][j].r == r1 && tab[i][j].c == c1){
				r2 = i;
				c2 = j;
				return true;
			}
		}
	}
	return false;
}

void show(int r, int c){
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			printf("[%d,%d]", tab[i][j].r, tab[i][j].c);
		}
		cout << endl;
	}
	cout << endl;
} 

int main(){
	
	int n, t;
	string s;
	
	while(cin >> r >> c && r != 0 && c != 0){
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				tab[i][j] = Cell(i, j);
			}
		}
		cin >> n;
		while(n--){
			cin >> s;
			if(s[0] == 'D'){
				cin >> t;
				for(int i = 0; i < t; i++){
					cin >> arr[i];
				}
				sort(arr, arr+t);
				for(int i = 0; i < t; i++){
					del(arr[i]-i, s[1]);
				}
			}else if(s[0] == 'I'){
				cin >> t;
				for(int i = 0; i < t; i++){
					cin >> arr[i];
				}
				sort(arr, arr+t);
				for(int i = 0; i < t; i++){
					ins(arr[i]+i, s[1]);
				}
			}else{
				cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
				exc(arr[1], arr[2], arr[3], arr[4]);
			}
		}
		cin >> n;
		if(cnt > 0){
			cout << endl;
		}
		printf("Spreadsheet #%d\n", ++cnt);
		while(n--){
			cin >> arr[1] >> arr[2];
			if(sch(arr[1], arr[2], arr[3], arr[4])){
				printf("Cell data in (%d,%d) moved to (%d,%d)\n", arr[1], arr[2], arr[3], arr[4]);
			}else{
				printf("Cell data in (%d,%d) GONE\n", arr[1], arr[2]);
			}
		}		
	}
	
	return 0;
}
/*
7 9
5
DR   2  1 5
DC  4  3 6 7 9
IC  1  3
IR  2  2 4
EX 1 2 6 5
4
4 8
5 5
7 8
6 5
0 0
*/


