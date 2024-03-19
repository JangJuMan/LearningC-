#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt=0;
    string input;
    cin >> input;
    for(char i : input){
        if(i == ','){
            cnt++;
        }
    }
    cout << cnt+1;
    return 0;
}