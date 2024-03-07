#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> ans;

    cin >> n;
    while(n){   
        ans.push_back(n%10);
        n/=10;
    }
    sort(ans.begin(), ans.end(), greater<int>());

    for(int i:ans){
        cout << i;
    }

    return 0;
}