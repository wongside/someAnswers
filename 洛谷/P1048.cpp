#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

struct Data {
	int x;
	int y;
};
Data data[105];

bool cmp(Data a,Data b){
	return (float)a.y / a.x > (float)b.y / b.x;
}

int main(){
	//文件重定向 
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int T,M;
	cin >> T >> M;
	for(int i = 0; i < M; i++){		
		cin >> data[i].x >> data[i].y;
	}
	sort(data,data + M,cmp);
	int sum = 0;
	for(int i = 0; i < M; i++){
		if(T - data[i].x >= 0){
			sum += data[i].y;
			T -= data[i].x;
		}
	}
	cout << sum;
	return 0;
}
