// Priority Queue : 보석 도둑
// https://www.acmicpc.net/problem/1202
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    long long sum=0;
    scanf("%d %d", &N, &K);

    vector<pair<int, int>> jewerlys(N);
    vector<int> bags(K);

    for(int i=0; i<N; i++){
        scanf("%d %d", &jewerlys[i].first, &jewerlys[i].second);
    }
    for(int i=0; i<K; i++){
        scanf("%d", &bags[i]);
    }
    sort(jewerlys.begin(), jewerlys.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    int index = 0;
    for(int i=0; i<K; i++){
        for(; index<N; index++){
            if(bags[i] < jewerlys[index].first){
                break;
            }
            pq.emplace(jewerlys[index].second);
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    printf("%lld", sum);

    return 0;
}