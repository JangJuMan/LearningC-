// Backtracking : N과 M(3)
// https://www.acmicpc.net/problem/15651
#include <iostream>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX];

void printArr(){
    for(int i=0; i<m; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void dfs(int depth){
    if(depth == m){
        printArr();
        return;
    }
    for(int i=1; i<=n; i++){
        arr[depth] = i;
        dfs(depth+1);
    }
}

int main(){
    cin >> n >> m;
    dfs(0);
    return 0;
}