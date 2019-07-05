#include <iostream>
#include <stack>
using namespace std;

struct Matrix{
	int r,c;
	
	Matrix(){
	}
	
	Matrix(int a, int b){
		r = a;
		c = b;
	}
};

Matrix mat[26];

int main(){
	
	int n, r, c;
	string exp;
	cin >> n;
	
	while(n--){
		cin >> exp >> r >> c;
		mat[exp[0] - 'A'] = Matrix(r, c);
	}
	
	while(cin >> exp){
		stack<Matrix> sta;
		int sum = 0;
		int len = exp.length();
		for(int i = 0; i < len; i++){			
			if(exp[i] == ')'){
				Matrix m2 = sta.top();
				sta.pop();
				Matrix m1 = sta.top();
				sta.pop();
				if(m1.c != m2.r){			
					sum = -1;
					break;
				}
				sum += m1.r * m1.c * m2.c;
				sta.push(Matrix(m1.r, m2.c));
			}else if(exp[i] != '('){
				Matrix m = mat[exp[i] -'A'];
				sta.push(m);
			}	
		}
		if(sum == -1){
			cout << "error" << endl;
		}else{
			cout << sum << endl;
		}
	}
	
	return 0; 
} 
