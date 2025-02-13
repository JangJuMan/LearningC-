// Topologycal Sort : 줄 세우기
// https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 32001

using namespace std;

int N, M;
int arr[N_MAX];
vector<int> vec[N_MAX];
queue<int> q;

int main(){
    int a, b;
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        arr[b]++;
        vec[a].emplace_back(b);
    }

    for(int i=1; i<=N; i++){
        if(arr[i] == 0){
            q.emplace(i);
        }
    }

    while(!q.empty()){
        int num = q.front();
        q.pop();
        printf("%d ", num);
        for(int i=0; i<vec[num].size(); i++){
            arr[vec[num][i]]--;
            if(arr[vec[num][i]] == 0){
                q.emplace(vec[num][i]);
            }
        }
    }
    return 0;
}