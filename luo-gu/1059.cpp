#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
	
	int n,t;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		s.insert(t);			//把读入的数据放入set 
	}
	cout << s.size() << endl;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout << *it << " ";		//遍历输出set中的数据 
	}
	
	return 0;
} 

/*
 *利用set去重并排序的特点，将数据存入set，再取出即可 
*/ 
