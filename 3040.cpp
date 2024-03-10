#include <bits/stdc++.h>

using namespace std;

int main(){
    int i, j, height[9]={0}, sum=0;
    bool isDone = false;

    for(i=0; i<9; i++){
        cin >> height[i];
        sum += height[i];
    }

    for(i=0; i<9; i++){
        for(j=i+1; j<9; j++){
            if(sum - height[i] - height[j] == 100){
                isDone = true;
                break;
            }
        }
        if(isDone){
            break;
        }
    }

    for(int k=0; k<9; k++){
        if(k!=i && k!=j){
            cout << height[k] << endl;
        }
    }
    
    return 0;
}