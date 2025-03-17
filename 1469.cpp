// Backtraking : 숌 사이 수열
// https://www.acmicpc.net/problem/1469
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX=9;
int N, arr[N_MAX];
bool isUsed[N_MAX];
bool isAns;
vector<int> vecX(N_MAX, -1);

void printS(){
    for(int i=0; i<2*N; i++){
        printf("%d ", vecX[i]);
    }
}

void dfs(int depth){
    if(isAns){          
        return;
    }
    if(depth == 2*N){
        isAns = true;      
        printS();
        return;             // or exit(0)로 프로그램 끝내버리기?
    }
    if(vecX[depth] != -1){
        dfs(depth+1);
        return;         
    }

    for(int i=0; i<N; i++){
        int secondIdx = depth + 1 + arr[i];
        if(!isUsed[arr[i]] && secondIdx < 2*N && vecX[secondIdx] == -1){
            // printf("second idx : %d\n", secondIdx);
            isUsed[arr[i]] = true;
            vecX[depth] = vecX[secondIdx] = arr[i];

            dfs(depth+1);

            isUsed[arr[i]] = false;
            vecX[depth] = vecX[secondIdx] = -1; 
        }
    }
}

int main(){
    scanf("%d", &N);
    vecX.reserve(2*N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);   // 사전 순으로 빠른 것부터 확인

    dfs(0);

    if(!isAns){         // 답을 찾지 못한 경우 -1 출력
        printf("-1");
    }
    return 0;
}