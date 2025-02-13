// Binary Search : 수찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
#define N_MAX 100001

using namespace std;

int N, M, arr[N_MAX], num;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &num);
        printf("%d\n", binary_search(arr, arr+N, num));
    }
    return 0;
}