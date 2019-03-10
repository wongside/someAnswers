#include <iostream> 
using namespace std;

#define LOCAL 0

int t[100];

int main(){
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout1.txt","w",stdout);
	cout << "#########################"<< endl;
#endif
	int n,m = 0;
	while((cin >> n),n){
		m++;
		int sum = 0,avg;
		for(int i = 0;i < n;i++){
			cin >> t[i];
			sum += t[i];
		}
		avg = sum / n;
		sum = 0;
		for(int i = 0;i < n;i++){			
			if(t[i] > avg)
				sum += (t[i] - avg);
		}
		cout << "Set #" << m << endl;
		cout << "The minimum number of moves is " << sum << ". " << endl;
		cout << endl;
	}
	
	return 0;
}
