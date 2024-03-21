#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    string input;
    cin >> T;
    while(T--){
        cin >> input;
        cout << input[0] << input[input.length()-1] << endl;
    }
    return 0;
}