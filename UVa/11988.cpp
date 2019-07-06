#include <iostream>
#include <cstring>
using namespace std;

char text[100005];
int  nest[100005];

int main(){

	while(scanf("%s", text+1) == 1){
		
		int lens = strlen(text+1);
		int head = 0;
		int tail = 0;
		int inst = 0;
		int prev = 0;
		for(int i = 1; i <= lens; i++){
			if(text[i] == '['){
				if(inst == 1){
					nest[prev] = head;
					head = nest[0];
				}else{
					head = nest[0];
					tail = prev;	
				}
				prev = 0;
				inst = 1;
			}else if(text[i] == ']'){
				if(inst == 1){
					inst = 0;
					nest[prev] = head;
					
					prev = tail;
				}
			}else{
				nest[prev] = i;
				prev = i;

			}
		}
		
		
//		cout << "---------------------------" << endl;
		for(int i = nest[0]; i != 0; i = nest[i]){
			printf("%c", text[i]);
//			cout << i << endl;
		}
		cout << endl;
//		cout << "---------------------------" << endl;
//		printf("%c\n", text[i]);
		memset(nest, 0, sizeof(int) * (lens + 1));
//nest[0] = 0;
	}
	
	
	return 0;
} 
