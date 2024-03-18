#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, sum=0;
    string input;
    cin >> N >> input;
    for(int i=0; i<N; i++){
        sum += input[i] - '0';
    }
    cout << sum;
    return 0;
}