#include <iostream>
#include <set>
#include <map>
using namespace std;
#define LOCAL 0


map<int,int> m;
int main(){ 
//�Ƿ��ض���  
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	
	int n,c;
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> c;
		int tmp,sum = 0;
		for(int j = 0; j < c; j++){
			cin >> tmp;
			if(j == c-1){//���ͳ�ƣ����Ǳ��������� 
				break;
			}
			sum += tmp;
			//������keyʱ��value�ĳ�ʼֵδ֪ 
//			if(m.find(sum) != m.end()){
				m[sum]++;				
//			}
//			else{
//				m[sum] = 1;
//			}					
		}		
	}
	int max = 0;
	map<int,int>::iterator p;
	for(p = m.begin();p != m.end();++p){
		if(p->second > max){
			max = p->second;
		}
	}
	cout << n-max << endl;
	return 0;
}
