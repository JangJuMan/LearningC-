#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#define N_MAX 51
#define M_MAX 51

using namespace std;

int N, M, K;
int arr[N_MAX][M_MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int row, int col){
    queue<pair<int, int>> q;
    q.emplace(make_pair(row, col));
    arr[row][col] = 0;

    while(!q.empty()){
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nextRow = nowRow + dy[i];
            int nextCol = nowCol + dx[i];
            if(nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M && arr[nextRow][nextCol] == 1){
                q.emplace(make_pair(nextRow, nextCol));
                arr[nextRow][nextCol] = 0;
            }
        }
    }
}

void dfs(int row, int col){
    arr[row][col] = 0;

    for(int i=0; i<4; i++){
        int nextRow = row + dy[i];
        int nextCol = col + dx[i];
        if(nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M && arr[nextRow][nextCol] == 1){
            dfs(nextRow, nextCol);
        }
    }
}

// FOR DEBUG
void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int ans=0;
        scanf("%d %d %d", &M, &N, &K);
        int a, b;
        for(int i=0; i<K; i++){
            scanf("%d %d", &a, &b);
            arr[b][a] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 1){
                    ans++;
                    dfs(i, j);
                    // bfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
        // memset(arr, 0, sizeof(arr));
    }
    return 0;
}