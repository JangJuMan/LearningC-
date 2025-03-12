// BFS, DFS : 수영장 만들기
// https://www.acmicpc.net/problem/1113
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, _max;
vector<vector<int>> vec;
struct pos{     // 이번엔 pair 대신 struct 만들어서 써보기
    int row;
    int col;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isInside(int row, int col){
    return (row >= 0 && row <= N+1 && col >= 0 && col <= M+1);
}

void bfs(int h){
    queue<pos> q;
    vec[0][0] = h;
    q.push({0, 0});
    // q.emplace({0, 0}); // emplace는 이렇게 안되는 듯

    while(!q.empty()){
        int row = q.front().row;
        int col = q.front().col;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextRow = row + dy[i];
            int nextCol = col + dx[i];
            if(isInside(nextRow, nextCol) && vec[nextRow][nextCol] < h){
                vec[nextRow][nextCol] = h;
                q.push({nextRow, nextCol});
            }
        }
    }
}

void dfs(int h, int row, int col){
    vec[row][col] = h;

    for(int i=0; i<4; i++){
        int nextRow = row + dy[i];
        int nextCol = col + dx[i];
        if(isInside(nextRow, nextCol) && vec[nextRow][nextCol] < h){
            dfs(h, nextRow, nextCol);
        }
    }
}

void init(){
    vec.resize(N+2, vector<int>(M+2, 0));
}

int main(){
    int ans=0;
    scanf("%d %d", &N, &M);
    init();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &vec[i][j]);
            _max = max(_max, vec[i][j]);
        }
    }

    for(int h=1; h<=_max; h++){
        // bfs(h);
        dfs(h, 0, 0);
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(vec[i][j] < h){
                    ans++;
                    vec[i][j]++;
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}
