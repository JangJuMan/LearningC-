#include <iostream>
#define N_MAX 100

using namespace std;

long long dp[N_MAX][N_MAX] = {1, };

void print_dp(int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int N;
    long long input;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> input;
            if(input == 0){
                continue;
            }
            if(input + i <= N){
                dp[i+input][j] += dp[i][j];
            }
            if(input + j <= N){
                dp[i][j+input] += dp[i][j];
            }
        }
    }

    cout << dp[N-1][N-1];

    return 0;
}