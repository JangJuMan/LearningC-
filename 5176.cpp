#include <bits/stdc++.h>

using namespace std;

int main(){
    int K, P, M, input, out_cnt;

    cin >> K;
    while(K--){
        out_cnt=0;
        cin >> P >> M;
        int seat[M+1] = {0};
        // vector<int> seat(M+1, 0);
        
        while(P--){
            cin >> input;
            if(seat[input] == 0){
                seat[input] = 1;
            }
            else if(seat[input] == 1){
                out_cnt++;
            }
        }
        cout << out_cnt << endl;
    }
    return 0;
}