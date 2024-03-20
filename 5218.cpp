#include <bits/stdc++.h>

#define ALPHABET_SIZE 26

using namespace std;

int main(){
    int N;
    string inputA, inputB;
    cin >> N;
    while(N--){
        cin >> inputA >> inputB;
        cout << "Distances: ";
        for(int i=0; i<inputA.length(); i++){
            int distance = inputB[i] - inputA[i];
            if(distance < 0){
                distance += ALPHABET_SIZE;
            }
            cout << distance << " ";
        }
        cout << endl;
    }
    return 0;
}