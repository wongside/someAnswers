#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
	
	int n,t;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		s.insert(t);			//�Ѷ�������ݷ���set 
	}
	cout << s.size() << endl;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout << *it << " ";		//�������set�е����� 
	}
	
	return 0;
} 

/*
 *����setȥ�ز�������ص㣬�����ݴ���set����ȡ������ 
*/ 
