#include <iostream>
#include <vector>
using namespace std;

int n, m, u, v;
int ans[1005];
vector<int> tab[1005];

void f(int x, vector<int> path){
	if(x == v){
		ans[0]++;
		for(unsigned int i = 0; i < path.size(); i++){
			ans[path[i]]++;
		}
		return;
	}
	for(int i = 0; i < tab[x].size(); i++){
		int next = tab[x][i];
		int tmp = 0;
		if(next != 0){			
			tab[x][i] = 0;
			for(int j = 0; j < tab[next].size(); j++){
				if(tab[next][j] == x){
					tmp = j;
				}
			}
			tab[next][tmp] = 0;
			path.push_back(next);
			f(next, path);
			path.pop_back();
			tab[x][i] = next;
			tab[next][tmp] = x;
		}
	}
}

int main(){
	int cnt = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		tab[u].push_back(v);
		tab[v].push_back(u);
	}
	cin >> u >> v;
	vector<int> path; 
	f(u, path);
	if(ans[0] != 0){
		for(int i = 1; i <= n; i++){
			if(ans[0] == ans[i]){
				cnt++; 
			}
		}
		cnt--;
	}else{
		cnt = -1;
	}
	cout << cnt;
	
	return 0;
}
