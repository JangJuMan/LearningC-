// BFS, Bitmask : 1194 달이 차오른다 가자
// https://www.acmicpc.net/problem/1194
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define NMAX 51
#define MMAX 51

using namespace std;

struct Node{
    int row, col, cnt, keys;
};

int N, M, ans=-1;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
bool isVisited[NMAX][MMAX][1<<6]; // 1을 6칸 shift left(=64)
vector<vector<char>> board;

bool isInside(int row, int col){
    return (row >= 0 && row < N && col >= 0 && col < M);
}

int bfs(int r, int c){
    isVisited[r][c][0] = true;
    queue<Node> q;
    q.push({r, c, 0, 0});

    while(!q.empty()){
        Node node = q.front();
        q.pop();
        // FOR DEBUG
        // printf("Cnt(%d), Board(%d, %d), Keys: ", node.cnt, node.row, node.col);
        cout << bitset<6>(node.keys) << "\n";

        for(int i=0; i<4; i++){
            int nextRow = node.row + dr[i];
            int nextCol = node.col + dc[i];
            int nextCnt = node.cnt + 1;
            int nextKeys = node.keys;
            bool canMove = false;
            int keyIdx, doorIdx;

            if(isInside(nextRow, nextCol)){
                switch (board[nextRow][nextCol]){
                    case '#':
                        continue;  // canMove = false;
                    case '.': case '0':
                        canMove = true;
                        break;
                    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
                        canMove = true;
                        keyIdx = board[nextRow][nextCol] - 'a';
                        nextKeys = node.keys | (1 << keyIdx);  // key index만큼 <<하고 OR 비트연산
                        break;
                    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
                        doorIdx = board[nextRow][nextCol] - 'A';
                        cout << "door : " << bitset<6>(node.keys) << bitset<6>(1 << doorIdx) << "\n";
                        if((node.keys & (1 << doorIdx)) != 0){
                            canMove = true;
                        }
                        break;
                    case '1':
                        return nextCnt;
                }
                if(!isVisited[nextRow][nextCol][nextKeys] && canMove){
                    isVisited[nextRow][nextCol][nextKeys] = true;
                    q.push({nextRow, nextCol, nextCnt, nextKeys});
                }
            }
        }
    }
    return -1;
}

void init(){
    board.resize(N, vector<char>(M, 0));
}

int main(){
    int startRow=0, startCol=0;
    scanf("%d %d", &N, &M);
    init();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf(" %c", &board[i][j]);
            if(board[i][j] == '0'){
                startRow = i;
                startCol = j;
            }
        }
    }
    cout << bfs(startRow, startCol);
    return 0;
}