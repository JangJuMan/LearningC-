#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;

    for(int i=0; i<input.length(); i++){
        if(isupper(input[i])){
            cout << (char)tolower(input[i]);
        }
        else if('a' <= input[i] && input[i] <= 'z'){
            cout << (char)(input[i] - ('a' - 'A'));
        }
    }
    return 0;
}