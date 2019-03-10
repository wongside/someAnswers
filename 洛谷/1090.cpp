#include <iostream>
#include <set>
using namespace std;


multiset<int> s;

int main(){
	int n, t, num;
	long long sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		s.insert(t);
	}
	multiset<int>::iterator it;
	while(s.size() > 1){		
		num = 0; 
		for(int i = 0;i < 2; i++){
			it = s.begin();
			num += *it;
			s.erase(it);	
		}
		sum += num;
		s.insert(num);		
	}	
	cout << sum;
	
	return 0;
}
