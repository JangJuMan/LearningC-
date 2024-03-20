#include <bits/stdc++.h>

#define ALPHABET_SIZE 26

using namespace std;

int main(){
    bool is_many = false;
    int alphabets[ALPHABET_SIZE]={0}, max=-1, max_idx=-1;
    string input;
    cin >> input;
    
    for(char i : input){
        alphabets[toupper(i) - 'A']++;
    }
    
    for(int i=0; i<ALPHABET_SIZE; i++){
        if(max == alphabets[i]){
            is_many = true;
        }
        else if(max < alphabets[i]){
            max = alphabets[i];
            max_idx = i;
            is_many = false;
        }
    }

    if(is_many){
        cout << "?";
    }
    else{
        cout << (char)(max_idx + 'A');
    }
    return 0;
}