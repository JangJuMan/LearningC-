// BFS : 노드사이의 거리
// https://www.acmicpc.net/problem/1240
// 트리라서 사이클이 없는 경우네...
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits>

using namespace std;

struct Edge{
    int to, weight;
};

const int N_MAX=1001;

int N, M;
bool isVisited[N_MAX];
vector<vector<Edge>> vec(N_MAX);

int bfs(int from, int to){
    queue<Edge> q;
    q.push({from, 0});
    isVisited[from] = true;

    while(!q.empty()){
        Edge curr = q.front();
        q.pop();
        if(curr.to == to){
            return curr.weight;
        }

        for(const auto &next : vec[curr.to]){
            if(!isVisited[next.to]){
                isVisited[next.to] = true;
                q.push({next.to, next.weight + curr.weight});
            }
        }
    }
    return -1;
}

void reset(){
    memset(isVisited, false, sizeof(isVisited));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N-1; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        vec[from].push_back({to, weight});
        vec[to].push_back({from, weight});
    }

    for(int i=0; i<M; i++){
        int from, to;
        cin >> from >> to;
        cout << bfs(from, to) << "\n";
        reset();
    }

    return 0;
}