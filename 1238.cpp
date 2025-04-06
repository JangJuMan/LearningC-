// 다익스트라 : 파티
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#include <queue>

using namespace std;

struct Edge{
    int to, cost;
    bool operator()(Edge a, Edge b){
        return a.cost > b.cost;
    }
};

const int N_MAX=1001, INF=numeric_limits<int>::max();
int N, M, X, res, ans, dist[N_MAX];
vector<vector<Edge>> vec(N_MAX);

void resetDist(){
    for(int i=0; i<=N; i++){
        dist[i] = INF;
    }
}

int dijkstra(int start, int end){
    resetDist();
    priority_queue<Edge, vector<Edge>, Edge> pq;    // q는 안돼

    pq.push({start, 0});
    dist[start] = 0;
    while(!pq.empty()){
        Edge curr = pq.top();
        pq.pop();

        if(curr.to == end){
            return dist[curr.to];
        }
        for(const auto &next : vec[curr.to]){
            if(dist[next.to] > next.cost + curr.cost){
                dist[next.to] = next.cost + curr.cost;
                pq.push({next.to, next.cost + curr.cost});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        int start, end, time;
        cin >> start >> end >> time;
        vec[start].push_back({end, time});
    }

    int ansGo, ansCome;
    for(int i=1; i<=N; i++){
        ansGo = dijkstra(i, X);
        ansCome = dijkstra(X, i);
        ans = max(ans, ansGo + ansCome);
    }
    cout << ans;
    
    return 0;
}