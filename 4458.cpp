#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    string input;

    cin >> N;
    cin.ignore();

    while(N--){
        getline(cin, input);
        input[0] = toupper(input[0]);
        cout << input << endl;
    }

    return 0;
}