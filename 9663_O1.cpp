// Backtracking : N-Queen
// https://www.acmicpc.net/problem/9663
// time complexit가 더 적을 것이라 판단했지만, 실제 실행시간은 훨씬 길었음
// 해쉬 충돌, 큰 해쉬를 다루는 과정에서 시간이 소요되지 않았을까...
// 참고영상 : https://www.youtube.com/watch?v=gcuZ_VGIcn4
#include <iostream>
#include <unordered_set>

#define MAX 15

using namespace std;

int N, cnt;
unordered_set<int> column;
unordered_set<int> rightDiagonal;
unordered_set<int> leftDiagonal;

bool isPosiible_O1(int row, int col){
    // 같은 행에 있으면 안 됨
    if(column.find(col) != column.end()){
        return false;
    }
    // 우측 하단 대각선에 있으면 안 됨
    if(rightDiagonal.find(row-col) != rightDiagonal.end()){
        return false;
    }
    // 좌측 하단 대각선에 있으면 안 됨
    if(leftDiagonal.find(row+col) != leftDiagonal.end()){
        return false;
    }
    return true;
}

void dfs(int row){
    if(row == N){
        cnt++;
        return;
    }
    for(int col=0; col<N; col++){
        if(isPosiible_O1(row, col)){
            column.insert(col);
            rightDiagonal.insert(row-col);
            leftDiagonal.insert(row+col);

            dfs(row+1);

            column.erase(col);
            rightDiagonal.erase(row-col);
            leftDiagonal.erase(row+col);
        }
    }
}

void init(){
    column.reserve(MAX);
    rightDiagonal.reserve(MAX);
    leftDiagonal.reserve(MAX);
}

int main(){
    init();
    cin >> N;
    dfs(0);
    printf("%d", cnt);
    return 0;
}