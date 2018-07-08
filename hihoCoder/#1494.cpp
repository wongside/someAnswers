#include <iostream>
#include <set>
#include <map>
using namespace std;
#define LOCAL 0


map<int,int> m;
int main(){ 
//是否重定向  
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n,c;
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> c;
		int tmp,sum = 0;
		for(int j = 0; j < c; j++){
			cin >> tmp;
			if(j == c-1){//最后不统计，但是必须先输入 
				break;
			}
			sum += tmp;
			//不存在key时，value的初始值未知 
//			if(m.find(sum) != m.end()){
				m[sum]++;				
//			}
//			else{
//				m[sum] = 1;
//			}					
		}		
	}
	int max = 0;
	map<int,int>::iterator p;
	for(p = m.begin();p != m.end();++p){
		if(p->second > max){
			max = p->second;
		}
	}
	cout << n-max << endl;
	return 0;
}
