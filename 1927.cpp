// Priority Queue : 최소 힙
// https://www.acmicpc.net/problem/1927
// cin은 느리다
#include <iostream>
#include <queue>

using namespace std;

// 비교 구조체
// struct cmp{
//     bool operator()(int a, int b){
//         return a > b;
//     }
// };

int N, input;
priority_queue<int, vector<int>, greater<int>> pq;  // min heap으로 생성
// priority_queue<int, vector<int>, cmp> pq;        // cmp 구조체 만들어서 사용 가능

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &input);  // cin 사용시 시간초과
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