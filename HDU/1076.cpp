#include <iostream> 
using namespace std;

#define LOCAL 1
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
	int n;
	cin >> n;
	while(n--){
		int a,b,cnt = 0;
		cin >> a >> b;
		while(1){
			if((a%4 == 0 && a%100 != 0) || a%400 == 0){
				cnt++;
				if(cnt == b)
					break;
			}
			if(cnt == 0)
				a++;
			else
				a += 4;			
		}
		cout << a << endl;
	}
	
	return 0;
}
