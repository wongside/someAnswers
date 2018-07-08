#include <iostream>
#include <map>
using namespace std;
#define LOCAL 0

map<int,int> m;//大的在前 

int gcd(int x,int y){
	
	if(m[x] == y){
		return 1;
	}else if(m[x] == -y){
		return 0;
	}else{
		int t = x % y;
		if(t == 0){
			if(y == 1){
				m.insert(pair<int,int>(x,y));
				return 1;
			}else{
				m.insert(pair<int,int>(x,-y));
				return 0;
			}
		}			
		return gcd(y,t);		
	}
	
}



int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int tmp,count = 0;
		cin >> tmp;
		for(int j = 1;j < tmp;j++){
			if(gcd(tmp,j) == 1)
				count++;
		}
		cout << count << endl;
	}
	
	
	return 0;
}
