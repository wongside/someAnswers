#include <iostream>
#include <algorithm>
using namespace std;

struct P{
	int num;
	int lan;
	int sco;
};

P stu[300+10];

int f(P a, P b){
	if(a.sco == b.sco){
		if(a.lan == b.lan){
			return a.num < b.num;
		}
		return a.lan > b.lan;
	}
	return a.sco > b.sco;
} 

int main(){
	int n, t1, t2, t3;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t1 >> t2 >> t3;
		stu[i].num = i;
		stu[i].lan = t1;
		stu[i].sco = t1 + t2 + t3;
	}
	sort(stu+1,stu+1+n,f);
	for(int i = 1; i <= 5; i++){
		cout << stu[i].num << " " << stu[i].sco << endl;
	}
	
	return 0;
} 
