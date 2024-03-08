#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, i, arr[10]={0}, max_1st, max_2nd, max_3rd, tmp;
    cin >> T;

    while(T--){
        max_1st = max_2nd = max_3rd = 0;

        for(i=0; i<10; i++){
            cin >> arr[i];
            if(max_1st < arr[i]){
                max_3rd = max_2nd;
                max_2nd = max_1st;
                max_1st = arr[i];
            }
            else if(max_2nd < arr[i]){
                max_3rd = max_2nd;
                max_2nd = arr[i];
            }
            else if(max_3rd < arr[i]){
                max_3rd = arr[i];
            }
        }
        cout << max_3rd << endl;
    }
    return 0;
}