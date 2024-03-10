#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> alphabet(26, -1);
    string S;
    cin >> S;
    
    for(int i=0; i<S.length(); i++){
        if(alphabet[S[i] - 'a'] == -1){
            alphabet[S[i] - 'a'] = i;
        }
    }

    for(int i : alphabet){
        cout << i << " ";
    }
    return 0;
}