// map : 듣보잡
// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, cnt=0;
    string input;
    cin >> N >> M;
    map<string, int> mp;
    
    for(int i=0; i<N+M; i++){
        cin >> input;
        mp[input]++;
        if(mp[input] == 2){
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(auto& i : mp){
        if(i.second == 2){
            cout << i.first << "\n";
        }
    }
    return 0;
}
