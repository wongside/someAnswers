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
	int n;
	cin >> n;
	while(n--){
		long long a,b,c,tmp;
		cin >> a >> b >> c;
		tmp = b-c - a;
		if(tmp > 0){
			cout << "advertise" << endl;
		}else if(tmp == 0){
			cout << "does not matter" << endl;
		}else{
			cout << "do not advertise" << endl;
		}
	}
	
	return 0;
}
