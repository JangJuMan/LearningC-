// MST : 불우이웃돕기
// https://www.acmicpc.net/problem/1414
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge{
    int from, to, cost;
};

using namespace std;

int N, total, mst, mstCount;
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
    edges.reserve(N*N);
    parents.resize(N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char input;
            scanf(" %c", &input);
            if(input != '0'){
                if(isupper(input)){
                    input = input - 'A' + 27;
                }
                else if(islower(input)){
                    input = input - 'a' + 1;
                }
                if(i != j){
                    edges.push_back({i, j, input});
                }
                total += input;
            }
        }
        parents[i] = i;
    }
    sort(edges.begin(), edges.end(), sortByCost);

    for(int i=0; i<edges.size(); i++){
        int fromParent = findParent(edges[i].from);
        int toParent = findParent(edges[i].to);
        if(fromParent != toParent){
            parents[toParent] = fromParent;
            mst += edges[i].cost;
            mstCount++;
        }
    }

    // MST 아닌 경우(MST는 Vertex -1개의 edge가 존재함)
    if(mstCount < N-1){ 
        printf("-1");
    }
    else{
        printf("%d", total - mst);
    }
    return 0;
}