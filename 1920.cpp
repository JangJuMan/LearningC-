// Binary Search : 수찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
#define N_MAX 100001

using namespace std;

int N, M, arr[N_MAX], num;

bool bSearch(int num){
    int left = 0;
    int right = N-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == num){
            return true;
        }
        else if(arr[mid] < num){
            left = mid+1;
        }
        else if(arr[mid] > num){
            right = mid-1;
        }
    }
    return false;
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &num);
        // STL ver
        // printf("%d\n", binary_search(arr, arr+N, num));

        // 구현 ver
        if(bSearch(num)){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}