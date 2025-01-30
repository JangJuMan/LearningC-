#include <iostream>
#define N_MAX 12
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

int N, ansMin=MAX, ansMax=MIN;
int nums[N_MAX];
int ops[4];

void dfs(int depth, int result){
    if(depth == N-1){
        ansMin = ansMin > result ? result : ansMin;
        ansMax = ansMax < result ? result : ansMax;
        return;
    }

    for(int i=0; i<4; i++){
        if(ops[i] > 0){
            ops[i]--;
            switch (i){
                case 0 :
                    // 다음 정수와 연산자를 계산한다
                    dfs(depth+1, result + nums[depth+1]);
                    break;
                case 1 :
                    dfs(depth+1, result - nums[depth+1]);
                    break;
                case 2 :
                    dfs(depth+1, result * nums[depth+1]);
                    break;
                case 3 :
                    dfs(depth+1, result / nums[depth+1]);
                    break;
            }
            ops[i]++;
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    for(int i=0; i<4; i++){
        cin >> ops[i];
    }

    dfs(0, nums[0]);

    printf("%d\n%d", ansMax, ansMin);

    return 0;
}