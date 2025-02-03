// Priority Queue : 최대 힙
// https://www.acmicpc.net/problem/11279
#include <iostream>
#include <queue>

using namespace std;

int N, input;
// priority_queue<int> pq; // default, 아래와 같음
priority_queue<int, vector<int>, less<int>> pq;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &input);
        if(input == 0){
            if(!pq.empty()){
                printf("%d\n", pq.top());
                pq.pop();
            }
            else{
                printf("0\n");
            }
        }
        else{
            pq.emplace(input);
        }
    }
    return 0;
}