// Greedy 1041. 주사위
// https://www.acmicpc.net/problem/1041
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX=1000000;
const int DICE_FACE = 6;
const int A=0, B=1, C=2, D=3, E=4, F=5;

int N;
vector<int> vec(DICE_FACE);

int main(){
    int sum=0, _max=-1;
    scanf("%d", &N);
    for(int i=0; i<6; i++){
        scanf("%d", &vec[i]);
        sum += vec[i];
        _max = max(_max, vec[i]);
    }
    if(N == 1){
        printf("%d", sum - _max);
        return 0;
    }

    int min_1 = min(vec[A], vec[F]);
    int min_2 = min(vec[B], vec[E]);
    int min_3 = min(vec[C], vec[D]);

    int minSum_3 = min_1 + min_2 + min_3;
    int minSum_2 = minSum_3 - max({min_1, min_2, min_3});
    int minSum_1 = min({min_1, min_2, min_3});

    long long ans = 4*minSum_3 + 4*(2*N-3)*minSum_2 + (5*(long long)N*N - 16*N + 12)*minSum_1;
    printf("%lld", ans); 
    
    return 0;
}