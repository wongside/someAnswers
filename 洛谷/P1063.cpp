#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;			//字典，用于存储单词对应的数值 
int num[10], cnt = 0;		//num存储从单词中分析出的数字，cnt表示数字个数 

int main()
{
	//将单词对应的数字存入map 
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["a"] = 1;
    m["both"] = 2;
    m["another"] = 1;
    m["second"] = 2;
    m["first"] = 1;
    m["third"] = 3;
    
    string str;
    for(int i = 0; i < 7; i++){						//6个单词加1个句号 
        cin >> str;									//输入数据 
        if(m.count(str) == 1){						//若是表示数字的单词 
        	num[cnt++] = (m[str] * m[str]) % 100;	//存入cum，并统计个数 
		}
    }
    
    sort(num, num+cnt);	//从小到大排列所有的数据 
    
    int pos = 0;		//记录从哪一位开始不是0 
    //将pos指向第一个不是0的数，小于cnt防止越界（回RE） 
    for(; pos < cnt && num[pos] == 0; pos++);   
    for(int i = pos; i < cnt; i++){				//从不是0的位置开始输出 
    	if(i != pos && num[i] < 10){			//不是第1个并且小于10
    		cout << 0;							//就输出0  
		}
		cout << num[i];							//否则直接输出原数 
	}
	if(pos == cnt){								//若所有数都为0(测试点3) 
		cout << 0;								//就直接输出0 
	}
    
    return 0;
}
