// Backtracking : N과 M(1)
// https://www.acmicpc.net/problem/15649
// endl은 굉장히 느리다, 여기서 endl을 사용한다면 시간초과가 나온다(\n 사용)
// endl은 버퍼를 비우는 것을 포함한 명령이기 때문이다.
#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0,};
bool isVisited[MAX] = {false};

void dfs(int depth){
    if(depth == m){
        for(int i=0; i<m; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int j=1; j<=n; j++){
        if(!isVisited[j]){
            isVisited[j] = true;
            arr[depth] = j;
            dfs(depth+1);
            isVisited[j] = false;
        }
    }

}

int main(){
    cin >> n >> m;
    dfs(0);
    return 0;
}