#include <iostream>
#define K_MAX 201
#define N_MAX 201
#define MOD 1000000000

using namespace std;

int dp[K_MAX][N_MAX];

int main(){
    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            if(j-1 >= 0){
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
            if(i-1 >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
    }
    cout << dp[k][n];
    return 0;
}