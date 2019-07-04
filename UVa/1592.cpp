#include <iostream>
#include <map>
using namespace std;

struct Node{
	int x;
	int y;
	
	Node(){
	}
	
	Node(int a, int b){
		x = a;
		y = b;
	}
	
	bool operator < (const Node & b) const {
		if(x == b.x){
			return y < b.y;
		}
		return x < b.x;
	}
};

map<string, int> idCathe;
int tab[10005][15];

string read(){
	string s = "";
	char ch;
	do{
		ch = getchar();
	}while(ch == '\n' || ch == '\r');
	for(; ch != '\n' && ch != '\r' && ch != ',' && ch != EOF; ch = getchar()){
		s += ch;
	}
	return s;
}

int getId(string s){
	if(idCathe.count(s) == 0){
		idCathe[s] = idCathe.size();
	}
	return idCathe[s];
}

void fun(int r, int c){
	
	for(int i = 0; i < c; i++){
		for(int j = i+1; j < c; j++){
			map<Node, int> m;
			for(int k = 0; k < r; k++){
				Node de = Node(tab[k][i], tab[k][j]);
				if(m.count(de) == 1){
					printf("NO\n");
					printf("%d %d\n", m[de]+1, k+1);
					printf("%d %d\n", i+1, j+1);
					return;
				}
				m[de] = k;
			}
		}
	}
	printf("YES\n");
}

int main(){
	
	int r, c;
	while(cin >> r >> c){
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				tab[i][j] = getId(read());
			}
		}
//		cout << "--------" << endl;
		fun(r, c);
	}
	
	
	return 0;
}
