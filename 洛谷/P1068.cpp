#include <iostream>
#include <algorithm>
using namespace std;

//定义存放编号和分数的结构体 
struct P{
	int num;			//编号 
	int sco;			//分数 
}p[5000+10];			//定义能装下数据的数组 

//排序的比较函数 
int f(P a, P b){
	if(a.sco == b.sco){
		return a.num < b.num;
	}
	return a.sco > b.sco;
}
int main(){
	int n,m;
	//输入数据
	cin >> n >> m;				 
	for(int i = 0; i < n; i++){
		cin >> p[i].num >> p[i].sco;
	}
	//使用stl中的sort进行排序 
	sort(p,p+n,f);
	//计算m的值 
	m = (m * 3) / 2;
	//分数等于最低分的也需要输出 
	while(p[m-1].sco == p[m].sco){
		m++;
	}
	//输出数据 
	cout << p[m-1].sco << " " << m << endl;
	for(int i = 0; i < m; i++){
		cout << p[i].num << " " << p[i].sco << endl;
	}
	
	return 0;
}
