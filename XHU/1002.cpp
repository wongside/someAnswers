#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	for(a = 10; a < 100; a++){
		b = a * 8;
		c = a * 9;
		d = b * 100 + c + 1;
		if(b>=10 && b<100 && c>=100 && c < 1000 && d>=1000 && d<10000) {
			printf("%d\n", a);
			printf("%d\n", d);
			printf("%d\n", b);
			printf("%d\n", c+1);
			printf("%d\n", c);
			return 0;
		}	
	}
	return 0; 
}
