#include <bits/stdc++.h>

using namespace std;

int main(){
    int N_int, M, cnt=0;
    cin >> N_int >> M;
    string N_str = to_string(N_int);

    for(int i=0; i<N_int; i++){
        for(int j=0; j<N_str.length() && cnt < M; j++, cnt++){
            cout << N_str[j];
        }
    }

    return 0;
}