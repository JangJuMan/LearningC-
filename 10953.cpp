#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, A, B, i, j;
    cin >> T;
    
    while(T--){
        // [1] scanf 지양
        // scanf("%d,%d", &A, &B);

        // [2] B < 10 조건으로 파싱
        string input;
        cin >> input;
        
        B = input[input.length()-1] - '0';
        // int i=~~,A=0 이런식으로 쓰면 for문 안에서만 쓸 A를 새로 만들어서 계산, 따라서 기존 A는 값의 변화X
        for(i=input.length()-3, j=1, A=0; i>=0; i--, j*=10){        
            A += (input[i] - '0') * j;
        }
        cout << A + B << endl;
        
    }
    return 0;
}