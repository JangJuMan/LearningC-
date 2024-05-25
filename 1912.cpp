#include <iostream>
#include <algorithm>

#define MAX 100000

using namespace std;

int input[MAX];
int dp[MAX];

int main(){
    int n, res;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> input[i];
    }

    dp[0]=input[0], res=input[0];

    for(int i=1; i<n; i++){
        dp[i] = max(input[i], dp[i-1] + input[i]);
        if(res < dp[i]){
            res = dp[i];
        }
    }

    cout << res;

    return 0;
}


// 10  -1  3   1   5   6   -35 12  21  -1
// 10  9   12  13  18  24  -11 12  33  32

// 2   1   -4  3   4   -4  6   5   -5  1
// 2   3   -1  3   7   3   9   14  9   10 

// -1  -2  -3  -4  -5
// -1  -2  -3  -4  -5

// -1  3   1   5   6   -35 12  21  -1
// -1  3   4   9   15  -20 12  35  34

    
