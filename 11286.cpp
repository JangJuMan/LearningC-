// Priority Queue : 절대값 힙
// https://www.acmicpc.net/problem/11286
#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        else{
            return abs(a) > abs(b);
        }
    }
};

priority_queue<int, vector<int>, cmp> pq;

int N, input;

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


// Pair<T, T> 버전
// // Priority Queue : 절대값 힙
// // https://www.acmicpc.net/problem/11286
// #include <iostream>
// #include <queue>

// using namespace std;

// struct cmp
// {
//     bool operator()(pair<int, int> &a, pair<int, int> &b){
//         if(a.first == b.first){
//             return a.second > b.second;
//         }
//         else{
//             return a.first > b.first;
//         }
//     }
// };

// priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

// int N, input;

// int main(){
//     scanf("%d", &N);
//     for(int i=0; i<N; i++){
//         scanf("%d", &input);
//         if(input == 0){
//             if(!pq.empty()){
//                 printf("%d\n", pq.top().second);
//                 pq.pop();
//             }
//             else{
//                 printf("0\n");
//             }
//         }
//         else{
//             pq.emplace(make_pair(abs(input), input));
//         }
//     }
//     return 0;
// }