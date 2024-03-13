#include <bits/stdc++.h>

using namespace std;

void ver1(){
    string input;
    cin >> input;
    cout << input.length();
}

void ver2(){
    int i;
    char str[101] = {0};
    scanf("%s", str);
    for(i=0; 1; i++){
        if(str[i] == '\0'){
            break;
        }
    }
    cout << i;
}

int main(){
    ver1();
    // ver2();
    return 0;
}