#include <iostream>
using namespace std;

int n, k, ans = 0;

/*
 *last:��һ��ѭ������ֵ
 *cur :��ǰ�ֵĸ���
 *sum :��ǰ�ۼƵ����� 
*/
void f(int last, int cur, int sum){
	if(cur == k){			//����ֵĸ�������Ҫ�ֵĸ�����ͬ�����˳� 
		if(n == sum){		//����ոշ��꣬��ͳ��һ�� 
			ans++;
		}
		return;
	}
	//��������Χ����ֹ����ֵ�����ǰ���С���Ӷ������ظ� 
	for(int i = last; sum + i*(k-cur) <= n; i++){
		f(i, cur+1, sum+i);
	}
}

int main(){
	cin >> n >> k;
	f(1, 0, 0);
	cout << ans;

	return 0;
} 
/*�ʼ�뵽�ķ�����dp�������ʼ�ҵ���״̬ת�Ʒ��������⣬����û��AC�� 
 *�����Լ�Ҳ�뵽���ö��for�������������Ĵ����õݹ���������ѭ������
 *û���Һã����·ֳ����������ظ���û��AC������dalao�ķ�������֪����ѭ��
 *����������AC�� 
*/ 
