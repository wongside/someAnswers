#include <iostream> 
using namespace std;

int main(){
	int m,n;
	cin >> m;
	for(int i = 0;i < m;i++){
		cin >> n;
		int sum = 0,num;
		for(int i = 0;i < n;i++){
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
		
	return 0;
}
