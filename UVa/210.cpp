#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;


char program[1005][10];
int nowLine[1005];
int nowUnlock = 0;
int var[26];
int islock = 0;
int lockflag = 0;
int nowend = 0;

int main(){
	int T, x = 0;
	int n, t[6], q;
	cin >> T;
	while(T--){
		x = 0;
		memset(program, 0, sizeof(program));
		memset(nowLine, 0, sizeof(nowLine));
		memset(var, 0, sizeof(var));
		queue<int> ready;
		queue<int> lockq;
		cin >> n >> t[1] >> t[2] >> t[3] >> t[4] >> t[5] >> q;
		cin.getline(program[0], 10);		//去除换行符 
		for(int i = 1; i <= n; i++){		//读入N个程序 
			nowLine[i] = x;					//第i个程序的首行 
			cin.getline(program[x++],10);	//读一行代码 
			while(program[x-1][2] != 'd'){	//是否读完一条程序 
				cin.getline(program[x++],10); 
			}
			ready.push(i);//将n个程序的pid加入执行队列 
		}
		int time, pid;
		time = q;							//当前程序的剩余时间 
		if(ready.size() <= 0){
			pid = 0;
		}else{
			pid = ready.front();				//取出一个程序pid 
			ready.pop();
		}							
		
		while(pid != 0){					//还有程序要执行 
			switch(program[nowLine[pid]][2]){//判断语句类型 
				case '=':
					sscanf(&program[nowLine[pid]][4],"%d",&var[program[nowLine[pid]][0] - 'a']);
					time -= t[1];
					break;
				case 'i':
					cout << pid << ": " << var[program[nowLine[pid]][6]-'a'] << endl;
					time -= t[2];
					break;
				case 'c':		
					if(islock == 0){
						islock = 1;
					}else{
						lockflag = 1;
					}
					time -= t[3];
					break;
				case 'l':
					islock = 0;
					if(lockq.size() > 0){
						nowUnlock = lockq.front();
						lockq.pop();
					}
					time -= t[4];
					break;
				case 'd':
					time -= t[5];
					nowend = 1;
					break;
			}
			nowLine[pid]++;
			if(time <= 0 || lockflag == 1){
				time = q;
				if(nowend == 1){
					nowend = 0;
				}else if(lockflag == 1){
					lockq.push(pid);
					lockflag = 0;
				}else{
					ready.push(pid);
				}
				if(nowUnlock != 0){
					pid = nowUnlock;
					nowUnlock = 0;
					nowLine[pid]--;
				}else{
					if(ready.size() > 0){
						pid = ready.front();
						ready.pop();
					}else{
						pid = 0;
					}
				}
			}
		}
		if(T){
			cout << endl;
		} 
		
//		for(int i = 0; i < n; i++){
//			cout << ready.front();
//			ready.pop();
//		}
		
//		for(int i = 0; i < x; i++){
//			for(int j = 0; j < 30; j++){
//				cout << program[i][j];
//			}
//			cout << endl;
//		}
	}
	
	return 0;
}
