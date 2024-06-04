#include <iostream>
#include <algorithm>
#define kMAX 10001
#define nMAX 101

using namespace std;

int coins[nMAX];
int dp[kMAX];

int main(){
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> coins[i];
    }

    for(int i=1; i<=K; i++){
        dp[i] = kMAX;
    }

    for(int num=1; num<=K; num++){
        for(int idx=1; idx<=N; idx++){
            if(num - coins[idx] >= 0){
                dp[num] = min(dp[num], dp[num - coins[idx]] + 1);
            }
        }
    }
    
    if(dp[K] == kMAX){
        cout << -1;
    }
    else{
        cout << dp[K];
    }
  
    return 0;
}