// unordered_map : 빈도정렬
// https://www.acmicpc.net/problem/2910
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, int> inputOrder;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second){
        return inputOrder[a.first] < inputOrder[b.first];
    }
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, C, input;
    cin >> N >> C;
    unordered_map<int, int> hashMap;

    for(int i=0; i<N; i++){
        cin >> input;
        hashMap[input]++;
        if(inputOrder.count(input) < 1){
            inputOrder[input] = i;
        }
    }

    // hash map 그대로 벡터에 넣기
    vector<pair<int, int>> vec(hashMap.begin(), hashMap.end());

    sort(vec.begin(), vec.end(), cmp);

    for(const auto& i : vec){
        for(int j=0; j<i.second; j++){
            cout << i.first << " ";
        }
    }
    return 0;
}