// unordered_map : 배부른 마라토너
// https://www.acmicpc.net/problem/10546
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    string str;
    unordered_map<string, int> members;     // 정렬 필요없음(hash_map)
    members.reserve(N);                     // rehahsing 방지 
    for(int i=0; i<N; i++){
        cin >> str;
        members[str]++;
    }
    for(int i=0; i<N-1; i++){
        cin >> str;
        members[str]--;
    }
    for(auto& i : members){
        if(i.second > 0){
            cout << i.first << "\n";
        }
    }

    return 0;
}
