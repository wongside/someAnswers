#include <iostream>
#include <algorithm>
using namespace std;

//�����ű�źͷ����Ľṹ�� 
struct P{
	int num;			//��� 
	int sco;			//���� 
}p[5000+10];			//������װ�����ݵ����� 

//����ıȽϺ��� 
int f(P a, P b){
	if(a.sco == b.sco){
		return a.num < b.num;
	}
	return a.sco > b.sco;
}
int main(){
	int n,m;
	//��������
	cin >> n >> m;				 
	for(int i = 0; i < n; i++){
		cin >> p[i].num >> p[i].sco;
	}
	//ʹ��stl�е�sort�������� 
	sort(p,p+n,f);
	//����m��ֵ 
	m = (m * 3) / 2;
	//����������ͷֵ�Ҳ��Ҫ��� 
	while(p[m-1].sco == p[m].sco){
		m++;
	}
	//������� 
	cout << p[m-1].sco << " " << m << endl;
	for(int i = 0; i < m; i++){
		cout << p[i].num << " " << p[i].sco << endl;
	}
	
	return 0;
}
