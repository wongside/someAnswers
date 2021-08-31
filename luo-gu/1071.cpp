#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

set<char> s, t;			//s�������ַ�����t�������ַ��� 
map<char,char> m;		//m�Ƕ��ߵĶ�Ӧ��ϵ 


int main(){
	int flag = 1;				//Ĭ��û��Υ������ 
	string s1, s2, s3;			//s1�����ģ�s2�����ģ�s3�������� 
	cin >> s1 >> s2 >> s3;
	for(unsigned int i = 0; i < s1.length(); i++){
		s.insert(s1[i]);				//�������ַ�����set 
		if(m[s1[i]] == 0){				//��û�и��ַ��Ķ�Ӧ��ϵ 
			m[s1[i]] = s2[i];			//����ö�Ӧ��ϵ 
			t.insert(s2[i]);			//���뵽���ļ��� 
		}else if(m[s1[i]] != s2[i]){	//��������֮ǰ�Ѿ���Ӧ����������	
			flag = 0;					//Υ������ 
			break;
		}		
	}
	
	if(s.size() != 26 || t.size() != 26){	//�����ĺ�������Ŀ���� 
		flag = 0;							//Υ������ 
	}
	
	if(flag){								//��û��Υ������ 
		for(unsigned int i = 0; i < s3.length(); i++){
			cout << m[s3[i]];				//������������Ķ�Ӧ������ 
		}
	}else{									//���� 
		cout << "Failed";					//���Failed 
	}
		
	
	return 0;
} 
