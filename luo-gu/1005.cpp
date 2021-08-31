#include <iostream>
#include <cmath>
using namespace std;
#define LOCAL 1

int tab[100][100];
int tmp[100][2];

long long sum;

int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> tab[i][j];
		}
	}
	for(int i = 0; i < 100; i++){
		tmp[i][1] = m-1;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < n; j++){
			if(tab[j][tmp[j][0]] > tab[j][tmp[j][1]]){
//				cout << tab[j][tmp[j][1]] << endl;				
				sum += tab[j][tmp[j][1]] * pow(2,i);
				tmp[j][1]--;
			}else{
//				cout << tab[j][tmp[j][0]] << endl;				
				sum += tab[j][tmp[j][0]] * pow(2,i);
				tmp[j][0]++;
			}
		}
	}
	cout << sum;
	
	
	return 0;
}
