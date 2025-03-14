// 백트래킹 : 1038 감소하는 수 / 이해가 잘 안가네
// https://www.acmicpc.net/problem/1038
#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 1000001;
int N;
long long DP[NMAX];

void solve(){
    queue<long long> q;
    for(int i=1; i<=9; i++){
        q.push(i);
        DP[i] = i;
    }

    if(0<=N && N<=10){
        printf("%d", N);
        return;
    }

    int idx = 10;
    while(!q.empty() && idx <= N){
        long long num = q.front();
        q.pop();

        int num0 = num % 10;
        for(int i=0; i<num0; i++){
            q.push(num * 10 + i);
            DP[idx++] = num * 10 + i;
        }
    }

    if(DP[N] != 0){
        printf("%lld", DP[N]);
    }
    else{
        printf("-1");
    }
}

int main(){
    scanf("%d", &N);
    solve();

    return 0;
}