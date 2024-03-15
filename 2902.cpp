#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;

    // [1] 그냥 대문자만 요약하면 되는거 아니야?
    for(int i=0; i<input.length(); i++){
        if(isupper(input[i])){
            cout << input[i];
        }
    }

    // [2] -(하이픈, ASCII 45) 이용한 구분
    /*cout << input[0];
    for(int i=0; i<input.length(); i++){
        if(input[i] == '-'){
            cout << input[i+1];
        }
    }*/

    return 0;
}