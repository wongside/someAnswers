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
	double sum = 0,num;
	while(cin >> num){
		sum += num;
	}
	char a[100];
	sprintf(a,"$%0.2f\n",sum/12);
	cout << a;
	return 0;
}
