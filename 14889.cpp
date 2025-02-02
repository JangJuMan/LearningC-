// Backtracking : 스타트와 링크
// https://www.acmicpc.net/problem/14889
// 처음엔 vector 2개로 팀 만들어서 풀다가, 배열 하나로 대체
// dfs 0부터 돌리면 시간초과라 startIdx부터 반복
#include <iostream>
#include <vector>
#define N_MAX 21
#define MAX 2147483647

using namespace std;

int N, S[N_MAX][N_MAX], minDiff=MAX;
bool isSelected[N_MAX];

int getDiff(){
    int sumA = 0;
    int sumB = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(isSelected[i] && isSelected[j]){
                sumA += S[i][j];   
            }
            else if(!isSelected[i] && !isSelected[j]){
                sumB += S[i][j];
            }
        }
    }
    return abs(sumA - sumB);
}

void dfs(int depth, int startIdx){
    if(depth == N/2){
        int diff = getDiff();
        minDiff = min(minDiff, diff);
        return;
    }

    for(int i=startIdx; i<N; i++){
        isSelected[i] = true;
        dfs(depth+1, i+1);
        isSelected[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> S[i][j];
        }
    }
    dfs(0, 0);
    printf("%d", minDiff);
    return 0;
}