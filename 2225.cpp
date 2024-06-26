#include <iostream>
#define N_MAX 201
#define K_MAX 201
#define MOD 1000000000

using namespace std;

int dp[K_MAX][N_MAX];

int main(){
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i=1; i<=k; i++){
        // printf("%d.\t", i);
        for(int j=0; j<=n; j++){
            if(j-1 >= 0){
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
            if(i-1 >= 0){
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }

            // printf("%d\t", dp[i][j]);
        }
        // cout << endl;
    }
    cout << dp[k][n];
    return 0;
}

//     0   1   2   3   4   5   6   7   8   9 N
// 0   1   -   -   -   -   -   -   -   -   - 
// 1   1   1   1   1   1   1   1   1   1   1
// 2   1   2   3   4   5   6   7   8   9   10
// 3   1   3   6   10  15  21  28
// 4   1   4   10  20  35  56  84
// 5   1   5   15  35  70  126
// 6   1   6   21  56  126 252
// 7   1
// 8   1
// 9   1
// K


// 00
// 01 10
// 02 11 20
// 03 12 21 30

// 04 13 22 31 40

// 05 14 23 32 41 50

// 000
// 001 010 100
// 002 020 200 011 101 110
// 003 030 300 012 102 120 021 201 210 111

// 40 / 004 040 400
// 13 / 013 103 130 
// 22 / 022 202 220
// 31 / 031 301 310
// 40 /    
// 112 / 112 121 211

// 04 13 22 31 40

// 004 013 022 031 040
// +

// 003 030 300 012 102 120 021 201 210 111
// 103 130 400 112 202 220 121 301 310 211