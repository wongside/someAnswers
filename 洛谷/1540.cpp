#include <iostream>
#include <queue> 
using namespace std;

queue<int> q;
int mp[1000+10];

int main(){
	int m,n,t,sum = 0;
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(mp[t] > 0){
			continue;
		}else{
			sum++;
			q.push(t);
			mp[t]++;
			if(q.size() > m){
				int tmp = q.front();
				mp[tmp]--;
				q.pop();
			}
		}
		
	}
	cout << sum;
	return 0;
}
