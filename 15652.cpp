// Backtracking : N과 M(4)
// https://www.acmicpc.net/problem/15652
// 중복가능, 비내림차순
#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX];

void printArr(){
    for(int i=0; i<m; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void dfs(int depth, int before){
    if(depth == m){
        printArr();
        return;
    }
    for(int i=before; i<=n; i++){
        arr[depth] = i;
        dfs(depth+1, i);
    }
}

int main(){
    cin >> n >> m;
    dfs(0, 1);
    return 0;
}