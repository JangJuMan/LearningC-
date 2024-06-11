#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int dp[MAX];

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> dp[i];
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<=i/2; j++){
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << dp[N];
    return 0;
}