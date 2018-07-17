#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct pa{
	int index;
	int value;
};

pa x[1000+10];
pa y[1000+10];

bool cmp(pa a, pa b){
	return (a.value > b.value);
}

int main(){
	
	int m,n,k,l,d;
	cin >> m >> n >> k >> l >> d;
	for(int i = 0; i < d; i++){
		int x1,y1,x2,y2,tmp;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 != x2){
			tmp = min(x1,x2);
			x[tmp].index = tmp;
			x[tmp].value++;
		}
		if(y1 != y2){
			tmp = min(y1,y2);
			y[tmp].index = tmp;
			y[tmp].value++;
		}
	}
	sort(x,x+1001,cmp);
	sort(y,y+1001,cmp);
	set<int> s[2];
	for(int i = 0; i < 1000; i++){
		if(i < k){
			s[1].insert(y[i].index);
		}
		if(i < l){
			s[0].insert(x[i].index);
		}
	}
	set<int>::iterator it;
	for(int i = 0; i < 2; i++){
		for(it = s[i].begin(); it != s[i].end(); ++it){
			if(it != s[i].begin()){
				cout << " ";
			}
			cout << *it;
		}
		if(i == 0){
			cout << endl;
		}
	}
	
	return 0;
}
