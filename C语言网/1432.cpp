#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> old;
int tab[15][15];
int m, n, ans = 0;
int tx[] = {-1, 1, 0, 0};
int ty[] = {0, 0, -1, 1};

int ok(int x, int y, string str){
	if(x < 0 || x >= m || y < 0 || y >= n){
		return 0;
	}
	return str[x * n + y];
}

int f(map<string, int> now, int cnt){
	if(now.size() == 0){
		return 0;
	}
	map<string, int> last;
	map<string, int>::iterator it;
	for(it = now.begin(); it != now.end(); it++){
		string str = (*it).first;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(str[i*n+j] == '1'){
					for(int k = 0; k < 4; k++){
						if(ok(i+tx[k], j+ty[k], str) == '0'){
							int sum = (*it).second + tab[i+tx[k]][j+ty[k]];						
							string tmp = str;
							tmp[(i+tx[k])*n+j+ty[k]] = '1';
							if(sum == ans){
								return cnt+1;
							}							
							last.insert(pair<string, int>(tmp, sum));
						}
					}
				}
			}
		}
	}
	return f(last, cnt+1);
}

int main(){
	string str = "";
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> tab[i][j];
			ans += tab[i][j];
			str += "0";
		}
	}
	if(ans%2 == 0){
		ans /= 2;
		map<string, int> now;
		str[0] = '1';
		now.insert(pair<string, int>(str, tab[0][0]));
		cout << f(now, 1);
	}else{
		cout << 0;
	}
	
	
	return 0;
}
