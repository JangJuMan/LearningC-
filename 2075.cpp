// Priority Queue : N번째 큰 수
// https://www.acmicpc.net/problem/2075
#include <iostream>
#include <queue>
#define N_MAX 1501

using namespace std;

int arr[N_MAX][N_MAX];
int curRow[N_MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
};

int main(){
    int N, input;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        curRow[i] = N-1;
        for(int j=0; j<N; j++){
            scanf("%d ", &arr[i][j]);
            // cin >> arr[i][j];
            if(i == N-1){
                pq.emplace(make_pair(arr[i][j], j));
            }
        }
    }

    for(int i=0; i<N-1; i++){
        int col = pq.top().second;
        pq.pop();
        curRow[col]--;
        pq.emplace(make_pair(arr[curRow[col]][col], col));
    }
    printf("%d", pq.top().first);
    return 0;
}