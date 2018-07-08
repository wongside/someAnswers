#include <iostream> 
using namespace std;

int main(){
	int n;
	while(1){
		cin >> n;
		if(n == 0)
			break;
		int sum = 0,num;
		for(int i = 0;i < n;i++){
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
		
	return 0;
}
