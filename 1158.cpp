// 큐 : 요세푸스 문제
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main(){
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++){
        q.emplace(i);
    }

    printf("<");
    while(!q.empty()){
        for(int i=0; i<K-1; i++){
            q.emplace(q.front());
            q.pop();
        }
        printf("%d", q.front());
        q.pop();

        if(!q.empty()){     // \b 는 stdout 비교할때 같이 비교되나보네...
            printf(", ");
        }
    }
    printf(">");
    return 0;
}