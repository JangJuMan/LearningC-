#include <iostream>
#define N_MAX 31

using namespace std;

int dp[N_MAX] = {0};

int main(){
    int n;
    cin >> n;

    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=n; i+=2){
        dp[i] = dp[2] * dp[i-2];
        for(int j=4; j<=i; j+=2){
            dp[i] = dp[i] + 2 * dp[i-j];
        }
        cout << dp[i] << endl;
    }
    cout << dp[n];
    return 0;
}