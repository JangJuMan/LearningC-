#include <iostream>
#include <map>

using namespace std;

int main(){
    // // ver 1
    int num[43] = {0};
    int n, cnt=0;
    for(int i=0; i<10; i++){
        cin >> n;
        num[n%42]++;
        cnt++;
        if(num[n%42] > 1){
            cnt--;
        }
    }
    cout << cnt;

    // ver2
    /*map<int, int> mp;
    int n;

    for(int i=0; i<10; i++){
        cin >> n;
        mp.insert({n%42, 1});    // mp.insert(pair<int, int>(n%42, 1));
    }
    cout << mp.size();*/
    
    return 0;
}