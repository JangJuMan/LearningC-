#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int height[9], sum=0, i, j;
    bool isDone = false;
    vector<int> ans;

    for(int i=0; i<9; i++){
        cin >> height[i];
        sum+=height[i];
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
            ans.push_back(height[k]);
        }
    }
    sort(ans.begin(), ans.end());

    for(int k : ans){
        cout << k << endl;
    }


    return 0;
}