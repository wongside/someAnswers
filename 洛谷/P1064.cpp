#include <iostream>
using namespace std;
#define LOCAL 0
const int maxn = 32010;	//�����ܵ���Ǯ�� 
const int maxm = 70;	//�����ܵ���Ʒ���� 

int main_w[maxm];		//�����ķ��� 
int main_c[maxm];		//�����ļ�ֵ 
int annex_w[maxm][3];	//�����ķ��� 0�������ĸ�����1������1�ķ��� 
int annex_c[maxm][3];	//�����ļ�ֵ 0�������ĸ�����1������1�ļ�ֵ 

int f[maxn];			//�� 


int main(){
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int n,m,v,p,q;
	cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> v >> p >> q;
        if (!q){				//Ϊ��������� 
            main_w[i] = v;
            main_c[i] = v * p;
        }
        else{					//Ϊ���������  
            annex_w[q][0]++;
            annex_w[q][annex_w[q][0]] = v;
            annex_c[q][annex_w[q][0]] = v * p;
        }
    }

    for (int i=1;i<=m;i++)
        for (int j=n;main_w[i]!=0 && j>=main_w[i];j--){
        	//������01���� 
            f[j] = max(f[j],f[j-main_w[i]]+main_c[i]);
			//����1�Ƿ񱳰� 
            if (j >= main_w[i] + annex_w[i][1])
                f[j] = max(f[j],f[ j - main_w[i] - annex_w[i][1] ] + main_c[i] + annex_c[i][1]);
			//����2�Ƿ񱳰� 
            if (j >= main_w[i] + annex_w[i][2])
                f[j] = max(f[j],f[ j - main_w[i] - annex_w[i][2] ] + main_c[i] + annex_c[i][2]);
			//����12ͬʱ���� 
            if (j >= main_w[i] + annex_w[i][1] + annex_w[i][2])
                f[j] = max(f[j],f[ j - main_w[i] - annex_w[i][1] - annex_w[i][2] ] + main_c[i] + annex_c[i][1] + annex_c[i][2]);

         }
     cout << f[n] << endl;	
	
	return 0;
}
