#include <bits/stdc++.h>

using namespace std;

int main(){
    int K, input, sum=0;
    cin >> K;

    vector<int> accountBook;

    while(K--){
        cin >> input;
        if(input == 0){
            accountBook.pop_back();
        }
        else{
            accountBook.push_back(input);
        }
    }

    for(int i : accountBook){
        sum += i;
    }

    cout << sum;
    return 0;
}