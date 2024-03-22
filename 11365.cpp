#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    while(1){
        getline(cin, input);
        if(input == "END"){   // c에서는 strcmp()
            break;
        }
        // 문자열 뒤집기
        // reverse(input.begin(), input.end());
        // cout << input << endl;

        // 하지만 굳이 문자열을 뒤집을 필요는 없지
        for(int i=input.length()-1; i>=0; i--){
            cout << input[i];
        }
        cout << endl;
    }

    return 0;
}