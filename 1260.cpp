#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define NMAX 1001
#define MMAX 10001

using namespace std;

int N, M, V;
bool isVisited[NMAX];
vector<int> vec[NMAX];

void bfs(int num){
    queue<int> q;
    q.emplace(num);
    isVisited[num] = true;

    while(!q.empty()){
        int a = q.front();
        q.pop();
        printf("%d ", a);
        for(int i=0; i<vec[a].size(); i++){
            if(!isVisited[vec[a][i]]){
                q.emplace(vec[a][i]);
                isVisited[vec[a][i]] = true;
            }
        }
    }
}

void dfs(int num){
    isVisited[num] = true;
    printf("%d ", num);

    for(int i=0; i<vec[num].size(); i++){
        if(!isVisited[vec[num][i]]){
            dfs(vec[num][i]);
        }
    }
}

void reset(){
    memset(isVisited, false, sizeof(isVisited));
    printf("\n");
}

int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].emplace_back(b);
        vec[b].emplace_back(a);
    }
    for(int i=1; i<=N; i++){
        sort(vec[i].begin(), vec[i].end());
    }
    dfs(V);
    reset();
    bfs(V);

    return 0;
}