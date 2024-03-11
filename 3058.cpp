#include <bits/stdc++.h>

#define MAX 101
#define SIZE 7

using namespace std;

int main(){
    int T, i, even_min, even_sum, input;
    cin >> T;

    while(T--){
        even_min=MAX, even_sum=0;
        for(i=0; i<SIZE; i++){
            cin >> input;
            if(input%2==0){
                if(even_min > input){
                    even_min = input;
                }
                even_sum+=input;
            }
        }
        cout << even_sum << " " << even_min << endl;
    }
    return 0;
}