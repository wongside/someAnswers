#include <iostream>
using namespace std;
#define LOCAL 0
const int maxn = 32010;	//最大可能的总钱数 
const int maxm = 70;	//最大可能的物品总数 

int main_w[maxm];		//主件的费用 
int main_c[maxm];		//主件的价值 
int annex_w[maxm][3];	//附件的费用 0：附件的个数；1：附件1的费用 
int annex_c[maxm][3];	//附件的价值 0：附件的个数；1：附件1的价值 

int f[maxn];			//答案 


int main(){
#if LOCAL
	freopen ("datain.txt","r",stdin);
    freopen ("dataout.txt","w",stdout);
#endif
	int n,m,v,p,q;
	cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> v >> p >> q;
        if (!q){				//为主件的情况 
            main_w[i] = v;
            main_c[i] = v * p;
        }
        else{					//为附件的情况  
            annex_w[q][0]++;
            annex_w[q][annex_w[q][0]] = v;
            annex_c[q][annex_w[q][0]] = v * p;
        }
    }

    for (int i=1;i<=m;i++)
        for (int j=n;main_w[i]!=0 && j>=main_w[i];j--){
        	//主件的01背包 
            f[j] = max(f[j],f[j-main_w[i]]+main_c[i]);
			//附件1是否背包 
            if (j >= main_w[i] + annex_w[i][1])
                f[j] = max(f[j],f[ j - main_w[i] - annex_w[i][1] ] + main_c[i] + annex_c[i][1]);
			//附件2是否背包 
            if (j >= main_w[i] + annex_w[i][2])
                f[j] = max(f[j],f[ j - main_w[i] - annex_w[i][2] ] + main_c[i] + annex_c[i][2]);
			//附件12同时背包 
            if (j >= main_w[i] + annex_w[i][1] + annex_w[i][2])
                f[j] = max(f[j],f[ j - main_w[i] - annex_w[i][1] - annex_w[i][2] ] + main_c[i] + annex_c[i][1] + annex_c[i][2]);

         }
     cout << f[n] << endl;	
	
	return 0;
}
