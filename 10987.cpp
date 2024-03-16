#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    int cnt=0;
    cin >> input;

    for(int i=0; i<input.length(); i++){
        // if문으로(취향껏)
        /*if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u'){
            cnt++;
        }*/

        // switch case 문으로
        switch (input[i])
        {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}