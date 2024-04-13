#include <iostream>

#define MODULO 1000000000

using namespace std;

int main(){
    int N;
    cin >> N;

    int DP[N+1][10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for(int i=1; i<=N; i++){
        for(int j=0; j<=9; j++){
            if(j>0){
                DP[i][j] = (DP[i][j] + DP[i-1][j-1]) % MODULO;
            }
            if(j<9){
                DP[i][j] = (DP[i][j] + DP[i-1][j+1]) % MODULO;
            }
        }
    }

    int res=0;
    for(int j=0; j<=9; j++){
        res = (res + DP[N-1][j]) % MODULO;
    }
    cout << res << endl;

    return 0;
}