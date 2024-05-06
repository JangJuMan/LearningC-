#include <iostream>

#define MAX 500

using namespace std;

int N, M;

int map[MAX][MAX], dp[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int i, int j){
    // printf("map[%d][%d] : %d Arrived!\n", i, j, map[i][j]);
    if(i == M-1 && j == N-1){
        // printf("ARRIVED!\n");
        return 1;
    }
    if(dp[i][j] != -1){
        // printf("DP[%d][%d] = %d DONE!\n", i, j, dp[i][j]);
        return dp[i][j];
    }

    dp[i][j] = 0;
    for(int tmp=0; tmp<4; tmp++){
        int next_i = i + dx[tmp];
        int next_j = j + dy[tmp];
        if(0 <= next_i && next_i < M && 0 <= next_j && next_j < N){
            if(map[next_i][next_j] < map[i][j]){
                dp[i][j] += dfs(next_i, next_j);
            }
        }
    }

    // // 같은말입니다
    // // 오른쪽 이동
    // if(j+1 < N){
    //     if(map[i][j+1] < map[i][j]){
    //         dp[i][j] += dfs(i, j+1);
    //     }
    // }
    // // 왼쪽이동
    // if(j-1 >= 0){
    //     if(map[i][j-1] < map[i][j]){
    //         dp[i][j] += dfs(i, j-1);
    //     }
    // }
    // // 위로이동
    // if(i-1 >= 0){
    //     if(map[i-1][j] < map[i][j]){
    //         dp[i][j] += dfs(i-1, j);
    //     }
    // }
    // // 아래로 이동
    // if(i+1 < M){
    //     if(map[i+1][j] < map[i][j]){
    //         dp[i][j] += dfs(i+1, j);
    //     }
    // }

    return dp[i][j];
}

int main(){
    cin >> M >> N;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);

    return 0;
}