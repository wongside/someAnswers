#include <iostream>
#include <cmath> 
using namespace std;

int readLen(){
	int tmp, sum = 0;
	for(int i = 0; i < 3; i++){
		while(!isdigit(tmp = getchar()));
		sum *= 2;
		sum += (tmp - '0');	
	}
	return sum;
}

int readNum(int len){
	
	int tmp, num = 0;
	for(int i = 0; i < len; i++){
		while(!isdigit(tmp = getchar()));
		num *= 2;
		num += (tmp - '0');	
	}
	
	if(num == pow(2, len) - 1){
		return -1;
	}
	
	//num++;
	for(int i = 1; i < len; i++){
		num += (pow(2, i) - 1);		
	}
	
	return num;
}



char tab[1000];

int readLine(){
	int pit = 1;
	while(tab[0] = getchar()){
		if(tab[0] == EOF){
			return 0;
		}
		if(tab[0] == '\n' || tab[0] == '\r'){
			continue;
		}
		break;
	}
	while((tab[pit++] = getchar()) != '\n' && tab[pit-1] != '\r');

	return 1;
}

/*
TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000
*/

int main(){
	
	int tmp;
	
	while(readLine()){
		
		for(int len = readLen(); len != 0; len = readLen()){
			while((tmp = readNum(len)) != -1){
				printf("%c", tab[tmp]);
			}
		}
		printf("\n");
	}
	
	return 0;
} 
