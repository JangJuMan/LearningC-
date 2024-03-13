#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K, used_coin=0;
    cin >> N >> K;

    int coin[N];
    for(int i=0; i<N; i++){
        cin >> coin[i];
    }

    for(int i=N-1; i>=0; i--){
        if(K >= coin[i]){
            used_coin += K/coin[i];
            K %= coin[i];
        }
    }
    cout << used_coin;

    return 0;
}