#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int input[MAX], dp[MAX];

int main(){
    int n, res=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> input[i];
        dp[i] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(input[i] < input[j]){
                dp[j] = max(dp[i]+1, dp[j]);
            }
        }
        res = max(res, dp[i]);
    }
    
    cout << res;
    return 0;
}