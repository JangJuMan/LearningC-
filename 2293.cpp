#include <iostream>
#define N_MAX 101
#define K_MAX 10001

using namespace std;

int coins[N_MAX];
int dp[K_MAX] = {1,};

int main(){
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coins[i];
        for(int j=coins[i]; j<=k; j++){
            dp[j] += dp[j-coins[i]];
        }
    }

    cout << dp[k];

    return 0;
}