#include <iostream>
using namespace std;

long long tab[200005];

int main(){
	
	int n, t, sum, maxsum;
	cin >> n >> t;
	maxsum = sum = t;
	for(int i = 1; i < n; i++){
		cin >> t;	
		if(sum < 0){
			sum = 0;
		}
		sum += t;
		if(sum > maxsum){
			maxsum = sum;
		}
	}
	cout << maxsum;
	
	return 0;
}
