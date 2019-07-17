#include <iostream>
#include <algorithm>
#include <sstream> 
using namespace std;

int cnt, tab[100];

void filp(int p){
	int m = (p+1) / 2;
	for(int i = 0; i < m; i++){
		swap(tab[i], tab[p-i]);
	}
	printf("%d ", cnt-p);
}

int main(){
	string str;
	while(getline(cin, str)){
		
		stringstream sin(str);
		cnt = 0;
		cout << str << endl;
		while(sin >> tab[cnt]) cnt++;
		for(int i = cnt; i > 0; i--){
			int p = max_element(tab, tab+i) - tab;
			if(p == i-1) continue;
			if(p){
				filp(p);
			}
			filp(i-1);
		}
		printf("0\n");
	}
	
	return 0;
} 
