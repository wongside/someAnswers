#include <iostream> 
using namespace std;

#define LOCAL 0
#if LOCAL
#include <fstream>
#include <ctime>
#endif

int main(){
#if LOCAL
	fstream cin("datain.txt",fstream::in);
	fstream cout("dataout.txt",fstream::app);
	cout << endl << "time:"<< time(0)%1000 << endl;
#endif
	int n,u,d;
	while(cin >> n >> u >> d){
		if(n == 0)
			break;
		int t = 0;
		int now = 0,flag = 1;		
		for(;now < n;t++){
			if(flag){
				now += u;
				flag = 0;
			}else{
				now -= d;
				flag = 1;
			}
		}
		cout << t << endl;
	}
	
		
	return 0;
}
