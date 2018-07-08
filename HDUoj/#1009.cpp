#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 0

struct Pa{
	int j;
	int f;
};

bool f(const Pa a,const Pa b){
	double x = double(a.j)/a.f;
	double y = double(b.j)/b.f;
	if(x > y)
		return 1;
	return 0;
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int m,n;
	while(cin >> m >> n && m != -1){
		Pa *t = new Pa[n];
		for(int i = 0;i < n;i++){
			cin >> t[i].j >> t[i].f;
		}
		sort(t,t+n,f);
		double max = 0;
		for(int i = 0;i < n;i++){
//			cout << "#" << t[i].j << " " << t[i].f << endl;
			if(m >= t[i].f){
				m -= t[i].f;
				max += t[i].j;
			}else{
				double tmp = double(t[i].j)/double(t[i].f);
				max += (double(m) * tmp);
				break;
			}
//			cout << "#" << max << endl;
		}
		printf("%0.3f\n",max);
		delete [] t;
	}
	
	return 0;
}
