// Backtraking 1182. 부분수열의 합
// https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 20;

int N, S, cnt;
vector<int> vec(NMAX);

void dfs(int idx, int sum){
    if(idx == N){
        return;
    }
    if(vec[idx]+sum == S){
        cnt++;
    }
    dfs(idx+1, sum);
    dfs(idx+1, sum+vec[idx]);
}

int main(){
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++){
        scanf("%d", &vec[i]);
    }
    dfs(0, 0);
    printf("%d", cnt);
    return 0;
}