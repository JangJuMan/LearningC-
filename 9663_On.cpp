// Backtracking : N-Queen
// https://www.acmicpc.net/problem/9663
#include <iostream>

#define MAX 15

using namespace std;

int N, cnt;
int chessCol[MAX];


bool isPossible_On(int row){
    for(int i=0; i<row; i++){
        // 같은 행에 있으면 안 됨
        if(chessCol[i] == chessCol[row]){
            return false;
        }
        // 대각선에 있으면 안 됨
        if(abs(row - i) == abs(chessCol[row] - chessCol[i])){
            return false;
        }
    }
    return true;
}

void dfs(int row){
    if(row == N){
        cnt++;
        return;
    }
    for(int col=0; col<N; col++){
        chessCol[row] = col;
        if(isPossible_On(row)){
            dfs(row+1);
        }
    }
}

int main(){
    cin >> N;
    dfs(0);
    printf("%d", cnt);
    return 0;
}