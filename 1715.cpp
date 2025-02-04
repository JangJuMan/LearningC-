// Priority Queue : 카드 정렬하기
// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
#define N_MAX 100001

using namespace std;

int N, input, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &input);
        pq.emplace(input);
    }

    while(!pq.empty()){
        int min1 = pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }
        else{
            int min2 = pq.top();
            pq.pop();
            int cost = min1 + min2;
            pq.emplace(cost);
            ans += cost;
        }
    }

    printf("%d\n", ans);
    return 0;
}