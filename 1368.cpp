// MST : 물대기
// https://www.acmicpc.net/problem/1368
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int from, to, cost;
};
int N, mst;
vector<Edge> edges;
vector<int> parents;

bool sortByCost(Edge a, Edge b){
    return a.cost < b.cost;
}

int findParent(int v){
    if(v == parents[v]){
        return v;
    }
    return parents[v] = findParent(parents[v]);
}

int main(){
    scanf("%d", &N);
    edges.reserve(N+1);
    parents.resize(N+1, 0);

    for(int i=1; i<=N; i++){
        int input;
        scanf("%d", &input);
        edges.push_back({0, i, input});
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int input;
            scanf("%d", &input);
            if(i < j){
                edges.push_back({i, j, input});
            }
        }
        parents[i] = i;
    }

    sort(edges.begin(), edges.end(), sortByCost);

    for(int i=0; i<edges.size(); i++){
        int fromParent = findParent(edges[i].from);
        int toParent = findParent(edges[i].to);
        if(fromParent != toParent){
            parents[fromParent] = toParent;
            mst += edges[i].cost;
        }
    }

    printf("%d", mst);
    return 0;
}