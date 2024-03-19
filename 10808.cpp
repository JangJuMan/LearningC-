#include <bits/stdc++.h>

using namespace std;

int main(){
    int alphabet[26] = {0};
    string input;
    cin >> input;

    for(char i : input){
        alphabet[i - 'a']++;
    }

    for(int i : alphabet){
        cout << i << " ";
    }

    return 0;
}