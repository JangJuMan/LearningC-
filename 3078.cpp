// 큐 : 좋은 친구
// https://www.acmicpc.net/problem/3078
#include <iostream>
#include <queue>

using namespace std;

const int MAX_NAME_LENGTH=21;

int N, K;


int main(){
    ios_base
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    string names[N+1];
    queue<int> q[MAX_NAME_LENGTH];

    for(int i=0; i<N; i++){
        cin >> names[i];
    }

    long long ans = 0;
    for(int i=0; i<N; i++){
        int len = names[i].size();
        while(!q[len].empty() && i - q[len].front() > K){
            q[len].pop();
        }
        ans += q[len].size();
        q[len].emplace(i);
    }
    cout << ans;

    return 0;
}

