#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    int dp[N+1][M+1]={0,};              // 왜 초기화가 안되는가..?
    memset(dp, 0, sizeof(dp));          // 내 컴파일러에서 초기화가 안되서 이거로..

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> dp[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + dp[i][j];
        }
    }

    cout << dp[N][M] << endl;
    return 0;   
}