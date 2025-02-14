// Two pointer : 부분합
// https://www.acmicpc.net/problem/1806
#include <iostream>
#define N_MAX 100001

using namespace std;

int arr[N_MAX];

int main(){
    int N, S;
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    int left=0, right=0, sum=0, minLen=N_MAX;
    while(left <= right){
        if(right == N+1){
            break;
        }

        if(sum >= S){
            minLen = min(minLen, right - left);
            sum -= arr[left++];
        }
        else{
            sum += arr[right++];
        }
    }
    if(minLen == N_MAX){
        printf("0\n");
    }
    else{
        printf("%d\n", minLen);
    }
    return 0;
}