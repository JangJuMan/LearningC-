#include <iostream>
#include <queue>

using namespace std;

// 
// struct cmp{
//     bool operator()(int a, int b){
//         return a > b;
//     }
// };

int N, input;
priority_queue<int, vector<int>, greater<int>> pq;
// priority_queue<int, vector<int>, cmp> pq;


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        scanf("%d", &input);
        // cin >> input;
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