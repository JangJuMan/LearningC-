#include <iostream>
#define N_MAX 100000
#define MODULO 9901

using namespace std;

int dp[N_MAX] = {3, 7};

int main(){
    int n;
    cin >> n;

    for(int i=2; i<n; i++){
        dp[i] = (dp[i-2] + 2*dp[i-1]) % MODULO;
    }

    cout << dp[n-1];
    return 0;
}