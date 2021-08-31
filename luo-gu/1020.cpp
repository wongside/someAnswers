#include <iostream>
using namespace std;

int tab[100005];
int dis[100005];
int t, n, sum = 1;

int dp(int i){
	if(i > n-2){
		return 1;
	}
	if(dis[i] > 0){
		return dis[i];
	}
	int flag = 0;
	dis[i] = 1;
	for(int j = i+1; j < n; j++){
		if(tab[i] >= tab[j]){
			flag++;
			dis[i] = max(dis[i], dp(j) + 1);
		}		
	}
	if(flag != 0){
		sum *= flag;
	}
	return dis[i];
}

int main(){
	
	
	for(n = 0; cin >> t; n++){
		tab[n] = t;
	}
	int m = dp(0);
	for(int i = 1; i < n; i++){
		m = max(m, dp(i));
	}
	cout << m << endl << sum;
	
	return 0;
}
