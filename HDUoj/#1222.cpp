#include <iostream>
using namespace std;

//����a��b����󹫱�����a > b�� 
int f(int a, int b){
	int tmp = a % b;	//��aģb 
	if(tmp == 0)		//��Ϊ0 
		return b;		//bΪ��󹫱��� 
	return f(b, tmp);	//����ݹ���� 
}

int main(){
	
	int p, m, n;
	cin >> p;
	while(p--){
		cin >> m >> n;
		if(f(n, m) == 1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	
	
	return 0;
} 
