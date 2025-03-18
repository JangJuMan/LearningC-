// MST : 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int from, to, cost;
};
int V, E;

vector<Edge> edges;
vector<int> parents;

bool sortByCost(Edge a, Edge b){
    return a.cost < b.cost;
}

int findParent(int vertex){
    if(parents[vertex] == vertex){
        return vertex;
    }
    return parents[vertex] = findParent(parents[vertex]);
}

int main(){
    int result=0;
    scanf("%d %d", &V, &E);

    edges.resize(E);
    parents.resize(V+1);

    for(int i=0; i<E; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[i].from = a;
        edges[i].to = b;
        edges[i].cost = c;
    }
    for(int i=1; i<=V; i++){
        parents[i] = i;
    }

    sort(edges.begin(), edges.end(), sortByCost);

    for(int i=0; i<E; i++){
        int fromParent = findParent(edges[i].from);
        int toParent = findParent(edges[i].to);
        // 동일 부모를 가진 vertex 2개를 연결하면, cycle이 생기므로 패스
        if(fromParent != toParent){
            parents[toParent] = fromParent;
            result += edges[i].cost;
        }
    }

    printf("%d", result);
    return 0;
}