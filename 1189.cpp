// backtraking : 1189 컴백홈
// https://www.acmicpc.net/problem/1189
#include <iostream>

using namespace std;

const int R_MAX = 5;
const int C_MAX = 5;

int R, C, K, cnt;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
char board[R_MAX][C_MAX];
bool isVisited[R_MAX][C_MAX];

bool isInside(int row, int col){
    return (row >=0 && row < R && col >= 0 && col < C);
}

void dfs(int row, int col, int depth){
    if(depth == K){
        if(row == 0 && col == C-1){
            cnt++;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(isInside(nr, nc) && board[nr][nc] != 'T' && !isVisited[nr][nc]){
            isVisited[nr][nc] = true;
            dfs(nr, nc, depth+1);
            isVisited[nr][nc] = false;
        }
    }
}

int main(){
    scanf("%d %d %d", &R, &C, &K);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf(" %c", &board[i][j]);
        }
    }

    isVisited[R-1][0] = true;
    dfs(R-1, 0, 1);
    printf("%d", cnt);
    return 0;
}