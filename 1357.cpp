#include <bits/stdc++.h>

using namespace std;

// [1] 진짜 숫자 뒤집어서 계산하기
int Rev(int x){
    vector<int> number;
    int result=0;

    while(x){
        number.push_back(x%10);
        x/=10;
    }

    for(int i=number.size()-1, j=0; i>=0; i--, j++){
        result += (number[i] * pow(10, j));
    }

    return result;
}

// [2] stoi, to_string 놀라운 기능 활용!
int Rev2(int x){
    string x_str = to_string(x);
    reverse(x_str.begin(), x_str.end());
    return stoi(x_str);
}

int main(){
    
    int X, Y;
    cin >> X >> Y;
    // cout << Rev(Rev(X) + Rev(Y)) << endl;
    cout << Rev2(Rev2(X) + Rev2(Y)) << endl;

    return 0;
}