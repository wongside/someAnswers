#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct S{
	string name;
	int num;
	int bur;
};

S s[100+10];

int f(S a, S b){
	if(a.bur == b.bur){
		return a.num < b.num;
	}
	return a.bur > b.bur;
}


int main(){
	int n, gra, sco, pap, sum = 0; 
	string name, gan, xibu;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> name >> gra >> sco;
		cin >> gan >> xibu >> pap;
		s[i].num = i;
		s[i].name = name;
		int tmp = 0;
		if(gra > 80 && pap > 0)
			tmp += 8000;
		if(gra > 85 && sco > 80)
			tmp += 4000;
		if(gra > 90)
			tmp += 2000;
		if(gra > 85 && xibu[0] == 'Y')
			tmp += 1000;
		if(sco > 80 && gan[0] == 'Y')
			tmp += 850;
		s[i].bur = tmp;
		sum += tmp;
	}
	
	sort(s+1,s+1+n,f);
	cout << s[1].name << endl;
	cout << s[1].bur << endl;
	cout << sum;
	
	return 0;
} 
