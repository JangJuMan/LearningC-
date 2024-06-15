#include <iostream>
#include <cmath>

#define MAX 100001

using namespace std;

int dp[MAX];

int main(){
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++){
        dp[i] = i;
        for(int j=1; j<=sqrt(i); j++){      // == (j*j <= i)
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    
    cout << dp[N];
    return 0;
}