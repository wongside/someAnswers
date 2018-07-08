#include <iostream> 
using namespace std;

#define LOCAL 0
#if LOCAL
#include <fstream>
#include <ctime>
#endif

int t[10005];

int main(){
#if LOCAL
	fstream cin("datain.txt",fstream::in);
	fstream cout("dataout.txt",fstream::app);
	cout << endl << "time:"<< time(0)%1000 << endl;
#endif
	int n;
	cin >> n;
	while(n--){
		int n,m,tmp,sum = 0;
		cin >> n >> m;
//		cout << "#" << n << " " << m << endl;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> tmp;
				if(tmp)
					sum++;
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}
