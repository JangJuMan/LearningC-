#include <iostream>
#define N_MAX 1000
#define RGB_SIZE 3
#define R 0
#define G 1
#define B 2

using namespace std;

int dp[N_MAX][RGB_SIZE];

int main(){
    int n, priceR, priceG, priceB;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> priceR >> priceG >> priceB;
        if(i==0){
            dp[0][R] = priceR;
            dp[0][G] = priceG;
            dp[0][B] = priceB;
        }
        else{
            dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + priceR;
            dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + priceG;
            dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + priceB;
        }
    }

    cout << min(dp[n-1][R], min(dp[n-1][G], dp[n-1][B]));
    return 0;
}