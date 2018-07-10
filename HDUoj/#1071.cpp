#include <iostream>
#include <string.h> 
using namespace std;
#define LOCAL 0

//three points 
double x1,x2,x3,y1,y2,y3; 	
//the coefficients of the two functions
double a,b,c,k,t;			
double s;	//area

int main(){   
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		
		a = (((y2-y1) / (x2-x1)) - ((y3-y2) / (x3-x2))) / (x1-x3);
        b = ((y2-y1) / (x2-x1)) - (a * (x1+x2));
        c = y3 - (a * x3 * x3 + b * x3);
		k = (y3 - y2) / (x3 - x2);
		t = y2 - k * x2;
        s = ((a / 3)*x3*x3*x3 + ((b-k)/2)*x3*x3 + (c-t)*x3)
        		- ((a / 3)*x2*x2*x2 + ((b-k)/2)*x2*x2 + (c-t)*x2);
		int m = s * 100 + 0.5;
		s = m / 100.0;
		printf("%0.2f\n",s);
	}
	
	return 0;
}
