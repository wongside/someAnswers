#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
	
	int t, n, tmp, cnt = 0;
	string cmd;
	
	while(cin >> t && t != 0){
		printf("Scenario #%d\n", ++cnt);
		map<int, int> teamId;
		queue<int> teamQueue;
		set<int> hasTeamId;
		queue<int> teamVec[1005];
		while(t--){
			cin >> n;
			while(n--){
				cin >> tmp;
				teamId[tmp] = t;
			}
		}
		int id;
		while(cin >> cmd && cmd[0] != 'S'){
			if(cmd[0] == 'E'){
				cin >> tmp;
				id = teamId[tmp];
				if(hasTeamId.count(id) == 0){
					teamQueue.push(id);
					hasTeamId.insert(id);
				}
				teamVec[id].push(tmp);
			}else{
				cout << teamVec[teamQueue.front()].front() << endl;
				teamVec[teamQueue.front()].pop();
				if(teamVec[teamQueue.front()].size() == 0){
					hasTeamId.erase(teamQueue.front());
					teamQueue.pop();
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}

/*
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0
*/
