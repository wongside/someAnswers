#include <cstdio>
#include <set>
using namespace std;

const int maxv = 1500;

set<long long> s;

int main(){
	
	long long t;
	
	s.insert(1);
	set<long long>::iterator it = s.begin();
	for(int i = 0; i < maxv; i++){
		t = *it;
		s.insert(2*t);
		s.insert(3*t);
		s.insert(5*t);
		if(i != maxv-1){
			it++;
		}		
	}
		
	printf("The 1500'th ugly number is %lld.\n", *it);

	
	
	return 0;
} 
