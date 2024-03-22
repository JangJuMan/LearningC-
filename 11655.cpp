#include <bits/stdc++.h>

#define ROT13 13
#define AlPHABET_SIZE 26

using namespace std;

int main(){
    string input;
    getline(cin, input);

    for(int i=0; i<input.length(); i++){
        if('A' <= input[i] && input[i] <= 'Z'){
            cout << char(((input[i] - 'A') + ROT13) % AlPHABET_SIZE + 'A');
        }
        else if('a' <= input[i] && input[i] <= 'z'){
            cout << char(((input[i] - 'a') + ROT13) % AlPHABET_SIZE + 'a');
        }
        else{
            cout << char(input[i]);
        }
    }
    return 0;
}