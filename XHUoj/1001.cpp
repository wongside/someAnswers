#include <iostream>
using namespace std;

const int maxn = 1005;
const long long mod = 1e9 + 7;
long long A[maxn][maxn];
long long B[maxn][maxn];


int main(){
	
	int n, p, m;
	cin >> n >> p >> m;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	long long sum = 0;
            for (int k = 0; k < p; k++) {
                sum += A[i][k] * B[k][j];
                sum %= mod;
            }
            cout << (sum + mod) % mod;
            if(j < m-1){
            	cout << " ";
			}
        }
        cout << endl;     
    }
    
    return 0;
}
