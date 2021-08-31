#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

set<char> s, t;			//s是密文字符集，t是明文字符集 
map<char,char> m;		//m是二者的对应关系 


int main(){
	int flag = 1;				//默认没有违反规则 
	string s1, s2, s3;			//s1：密文；s2：明文；s3：待解密 
	cin >> s1 >> s2 >> s3;
	for(unsigned int i = 0; i < s1.length(); i++){
		s.insert(s1[i]);				//将密文字符放入set 
		if(m[s1[i]] == 0){				//若没有该字符的对应关系 
			m[s1[i]] = s2[i];			//存入该对应关系 
			t.insert(s2[i]);			//插入到明文集中 
		}else if(m[s1[i]] != s2[i]){	//若该密文之前已经对应其他的明文	
			flag = 0;					//违反规则 
			break;
		}		
	}
	
	if(s.size() != 26 || t.size() != 26){	//若密文和明文数目不够 
		flag = 0;							//违反规则 
	}
	
	if(flag){								//若没有违反规则 
		for(unsigned int i = 0; i < s3.length(); i++){
			cout << m[s3[i]];				//输出待解密密文对应的明文 
		}
	}else{									//否则 
		cout << "Failed";					//输出Failed 
	}
		
	
	return 0;
} 
