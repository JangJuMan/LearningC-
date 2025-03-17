// Knapsack : 호텔
// https://www.acmicpc.net/problem/1106
#include <iostream>
#include <vector>

using namespace std;

struct city{
    int cost, customerCnt;
};

const int NMAX=21, CMAX=1001, INTMAX=2147483647;

int C, N, dp[CMAX]; // 고객을 C명 늘이기 위해 투자한 최소 투자값
vector<city> citys;

int main(){
    int a, b;
    scanf("%d %d", &C, &N);
    citys.reserve(N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &a, &b);
        citys[i].cost = a;
        citys[i].customerCnt = b;
    }

    for(int i=1; i<=C; i++){
        dp[i] = INTMAX;
        for(int j=0; j<N; j++){
            if(i <= citys[j].customerCnt){
                dp[i] = min(dp[i], citys[j].cost);
            }
            else{
                dp[i] = min(dp[i], dp[i-citys[j].customerCnt] + citys[j].cost);
            }
        }
    }
    printf("%d", dp[C]);
    
    return 0;
}