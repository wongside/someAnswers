#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> tobig(long long n){
	vector<int> res;
	while(n > 0){
		res.push_back(n%10);
		n /= 10;
	}
	return res;
}

void printbig(vector<int> n){
	for(int i = n.size()-1; i >= 0; i--){
		cout << n[i];
	}
}

vector<int> add(vector<int> a, vector<int> b){
	if(b.size() > a.size()){
		vector<int> tmp = b;
		b = a;
		a = tmp;
	}
	vector<int> sum;
	int len = a.size() - b.size();
	for(int i = 0; i < len; i++){
		b.push_back(0);
	}
	len = a.size();
	int tmp = 0;
	for(int i = 0; i < len; i++){
		tmp += a[i] + b[i];
		sum.push_back(tmp%10);
		tmp /= 10;
	}	
	if(tmp != 0){
		sum.push_back(tmp);
	}
	return sum;
}

vector<int> f(int a, int n, int k){
	int tmp = pow(2, k);
	if(n == 1){
		return tobig(tmp - 1 - a);
	}
	vector<int> sum;
	for(int i = a+1; i < tmp; i++){
		sum = add(sum, f(i, n-1, k));	
	}
	return sum;
}

int main(){	
	
	int k, w, len;
	cin >> k >> w;
	len = w / k;
	vector<int> sum;
	
	for(int i = 2; i <= len; i++){
		sum = add(sum, f(0, i, k));
	}
	
	int cnt = pow(2, w - len * k);
	for(int i = 1; i < cnt; i++){
		sum = add(sum, f(i, len, k));
	}
	
	printbig(sum);
	
	return 0;
}
