#include <iostream> 
using namespace std;

#define LOCAL 1

int main(){
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
	cout << "#########################"<< endl;
#endif
	int m,n;
	cin >> m;
	while(m--){
		cin >> n;
		int sum = 0,num;
		for(int i = 0;i < n;i++){
			cin >> num;
			sum += num;
		}
		cout << sum;
		cout << endl << endl;
	}
		
	return 0;
}
