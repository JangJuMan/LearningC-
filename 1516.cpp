// 위상정렬 : 게임 개발
// https://www.acmicpc.net/problem/1516
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N_MAX = 501;
int N, buildTime[N_MAX], preCondition[N_MAX], dp[N_MAX];
vector<vector<int>> buildSeq;

void bfs(){
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(preCondition[i] == 0){
            q.emplace(i);
            dp[i] = buildTime[i];
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : buildSeq[curr]){
            preCondition[next]--;
            dp[next] = max(dp[next], dp[curr] + buildTime[next]);
            if(preCondition[next] == 0){
                q.emplace(next);
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    buildSeq.resize(N+1, vector<int>());
    
    int input;
    for(int i=1; i<=N; i++){
        scanf("%d", &buildTime[i]);
        while(scanf("%d", &input)){
            if(input == -1){
                break;
            }
            buildSeq[input].emplace_back(i);
            preCondition[i]++;
        }
    }

    bfs();
    for(int i=1; i<=N; i++){
        printf("%d\n", dp[i]);
    }
    return 0;
}