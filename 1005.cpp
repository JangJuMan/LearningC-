// Topologycal Sort : ACM Craft
// https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 1001 // 이걸 1000으로 해두면 70%에서 틀립니다 ㅎㅎ
#define D_MAX 100001

using namespace std;

int T, N, K, W;
int preCondition[N_MAX], D[N_MAX], dp[N_MAX];
vector<int> vec[N_MAX];

void clear(){
    for(int i=0; i<=N; i++){
        preCondition[i] = 0;
        D[i] = 0;
        dp[i] = 0;
        vec[i].clear();
    }
}

void bfs(){
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(preCondition[i] == 0){
            q.emplace(i);
            dp[i] = D[i];
        }
    }

    while(!q.empty()){
        int curr = q.front();
        // printf("[DEBUG] curr : %d\n", curr);
        q.pop();

        for(int i=0; i<vec[curr].size(); i++){
            int next = vec[curr][i];
            preCondition[next]--;
            // printf("[DEBUG] next : %d \tdp[%d] = max(%d, %d+%d) = %d\n", next, next, dp[next], dp[curr], D[next], max(dp[next], dp[curr]+D[next]));
            dp[next] = max(dp[next], dp[curr] + D[next]);

            if(preCondition[next] == 0){
                q.emplace(next);
                // printf("[DEBUG] %d push\n", next);
            }
        }
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        for(int i=1; i<=N; i++){
            scanf("%d", &D[i]);
        }

        for(int i=0; i<K; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            preCondition[b]++;
            vec[a].emplace_back(b);
        }

        scanf("%d", &W);
        bfs();
        printf("%d\n", dp[W]);

        clear();
    }
    return 0;
}