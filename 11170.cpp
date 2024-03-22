#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, N, M, cnt, i;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(i=N, cnt=0; i<=M; i++){
            string num_str = to_string(i);
            cnt += count(num_str.begin(), num_str.end(), '0');
        }
        cout << cnt << endl;
    }
    return 0;
}