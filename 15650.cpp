// Backtracking : N과 M(2)
// https://www.acmicpc.net/problem/15650
#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX];
bool isVisited[MAX];

void dfs(int depth, int before){
    if(depth == m){
        for(int i=0; i<depth; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int j=before; j<=n; j++){
        if(!isVisited[j]){
            isVisited[j] = true;
            arr[depth] = j;
            dfs(depth+1, j);
            isVisited[j] = false;
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    dfs(0, 1);
    return 0;
}