#include <iostream>
#define MAX 11

using namespace std;

int dp[MAX] = {0, 1, 2, 4};

int main(){
    int n, input;
    cin >> n;

    for(int i=4; i<MAX; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    for(int i=0; i<n; i++){
        cin >> input;
        cout << dp[input] << endl;
    }

    return 0;
}