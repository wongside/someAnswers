#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> pile[30];

void find(int a, int &p, int &h){
	for(p = 0; p < n; p++){
		for(h = 0; h < (int)pile[p].size(); h++){
			if(pile[p][h] == a){
				return;
			}
		}
	}
}

void clear(int p, int h){
	for(int i = h+1; i < (int)pile[p].size(); i++){
		int tmp = pile[p][i];
		pile[tmp].push_back(tmp);
	}
	pile[p].resize(h+1);
}

void moveTo(int p, int h, int t){
	for(int i = h; i < (int)pile[p].size(); i++){
		pile[t].push_back(pile[p][i]);
	}
	pile[p].resize(h);
}

int main(){
	string s1, s2;
	int a, b;
	cin >> n;
	for(int i = 0; i < n; i++){
		pile[i].push_back(i);
	}
	while(cin >> s1 >> a >> s2 >> b){		  
		int pa, pb, ha, hb;
		find(a, pa, ha);
		find(b, pb, hb);
		if(pa == pb){
			continue;
		}
		if(s1 == "move"){
			clear(pa, ha);
		}
		if(s2 == "onto"){
			clear(pb, hb);
		}
		moveTo(pa, ha, pb);
	}
	for(int i = 0; i < n; i++){
		printf("%d:", i);
		for(int j = 0; j < (int)pile[i].size(); j++){
			printf(" %d", pile[i][j]);
		}
		cout << endl;
	} 
	
	 
	return 0;
}
