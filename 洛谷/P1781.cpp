#include <iostream>
#include <algorithm>
using namespace std;

//����ṹ�� 
struct P{
	int num;			//��� 
	string val;			//Ʊ�� 
}pa[25];				//�洢�������ݵ����� 

//����ıȽϺ��� 
int f(P a, P b){
	//�����������ֵ 
	string s1 = a.val;
	string s2 = b.val;
	//�ַ������ʱ�������λ�����λ�ж����Ĵ�С 
	if(s1.length() == s2.length()){
		for(unsigned int i = 0; i < s1.length(); i++){
			//���λԽ����Խ�� 
			if(s1[i] > s2[i]){
				return 1;
			}else if(s1[i] < s2[i]){
				return 0;
			}
			//���������ô���
		}
	}
	//����λ��Խ�࣬����Խ�� 
	return s1.length() > s2.length();
}

int main(){
	int n;
	//�������� 
	cin >> n;
	for(int i = 1; i <= n; i++){
		pa[i].num = i;
		cin >> pa[i].val;
	}
	//ʹ��f�������� 
	sort(pa+1,pa+n+1,f);
	//������ 
	cout << pa[1].num << endl;
	cout << pa[1].val << endl;
	
	return 0;
}
