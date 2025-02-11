// Priority Queue : 문제집
// https://www.acmicpc.net/problem/1766
#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 32001

using namespace std;

int N, M;
int preCondition[N_MAX];
vector<int> vec[N_MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    scanf("%d %d\n", &N, &M);
    // cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d\n", &a, &b);
        // cin >> a >> b;
        vec[a].emplace_back(b);
        preCondition[b]++;
    }

    for(int i=1; i<=N; i++){
        if(preCondition[i] == 0){
            pq.emplace(i);
        }
    }

    while(!pq.empty()){
        int num = pq.top();
        pq.pop();
        printf("%d ", num);

        for(int i=0; i<vec[num].size(); i++){
            preCondition[vec[num][i]]--;
            if(preCondition[vec[num][i]] == 0){
                pq.emplace(vec[num][i]);
            }
        }
    }
    
    return 0;
}