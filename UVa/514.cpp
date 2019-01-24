#include <iostream>
#include <stack> 
using namespace std;

int tab[1005];

int main(){
	int n;
	while(scanf("%d",&n) == 1 && n != 0){
		stack<int> s;
		int first;
		scanf("%d",&first);
		while(first != 0){
			tab[1] = first; 
			for(int i = 2; i <= n; i++){
				scanf("%d",&tab[i]);
			}
			scanf("%d",&first);
			int a = 1, b = 1, ok = 1;
			while(b <= n){
				if(!s.empty() && s.top() == tab[b]){
					s.pop();
					b++;
				}else if(a <= n){
					s.push(a++);
				}else{
					ok = 0;
					break;
				}
				
			}
			printf("%s\n",ok?"Yes":"No");
		}
		printf("\n");
	}
	
	return 0;
} 
