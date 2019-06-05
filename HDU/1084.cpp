#include <iostream>
#include <algorithm>
using namespace std;
#define LOCAL 1

struct stu{
	int p;
	int h;
	int m;
	int s;
	int o;
	int g;
}s[105];

bool f(const stu a,const stu b){
	if(a.p > b.p)
		return 1;
	else if(a.p < b.p)
		return 0;
	else{
		if(a.h < b.h)
			return 1;
		else if(a.h > b.h)
			return 0;
		else{
			if(a.m < b.m)
				return 1;
			else if(a.m > b.m)
				return 0;
			else{
				if(a.s < b.s)
					return 1;
				return 0;
	
			} 
		} 
	} 
}

int grade(int i,int p,int g){
	int cnt = 1;
	for(int j = i+1;;j++){
		if(s[j].p != p)
			break;
		if(s[j].p == p){
			cnt++;						
		}
	}
	int tmp = cnt/2;
	for(int k = 0;k < tmp;k++){
		s[k+i].g = g + 5;
	}
	for(int k = 0;k < cnt - tmp;k++){
		s[k+i+tmp].g = g;
	}
	return i+cnt-1;
}

bool f2(const stu a,const stu b){
	if(a.o < b.o)
		return 1;
	return 0;
}

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int n;
	while(cin >> n && n > 0){
		char tab[8];
		for(int i = 0;i < n;i++){
			cin >> s[i].p;
			cin >> tab;
			s[i].h = (tab[0]-'0') * 10 + (tab[1]-'0');
			s[i].m = (tab[3]-'0') * 10 + (tab[4]-'0');
			s[i].s = (tab[6]-'0') * 10 + (tab[7]-'0');
			s[i].o = i;
		}
		sort(s,s+n,f);
		for(int i = 0;i < n;i++){
			
			if(s[i].p == 5){
				s[i].g = 100;
			}
			if(s[i].p == 4){
				i = grade(i,4,90);	
			}
			if(s[i].p == 3){
				i = grade(i,3,80);	
			}
			if(s[i].p == 2){
				i = grade(i,2,70);	
			}
			if(s[i].p == 1){
				i = grade(i,1,60);	
			}
			if(s[i].p == 0){
				s[i].g = 50;
			}
/*			
			cout << s[i].p << " ";
			cout << s[i].h << " ";
			cout << s[i].m << " ";
			cout << s[i].s << endl;
*/			
		}
		sort(s,s+n,f2);
		for(int i = 0;i < n;i++){
			cout << s[i].g << endl;
		}
		cout << endl;
	}
	
	return 0;
}
