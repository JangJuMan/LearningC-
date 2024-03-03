#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 1000

using namespace std;

int sorted[MAX_SIZE] = {0};

void print_vector(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

void merge(int list[], int left, int mid, int right){
    int minLeft, minRight, sortedIndex, i;
    minLeft = left;
    minRight = mid + 1;
    sortedIndex = left;

    // '왼쪽배열'의 가장 작은수 vs '오른쪽배열'의 가장 작은수 비교하기
    while(minLeft <= mid && minRight <= right){
        // 더 작은 수를 '결과배열'에 저장하기
        if(list[minLeft] <= list[minRight]){
            sorted[sortedIndex++] = list[minLeft++];
        }
        else{
            sorted[sortedIndex++] = list[minRight++];
        }
    }

    // 만약 한쪽 배열에 남은 값이 있다면 그 순서대로 '결과배열'에 저장하기
    if(minLeft > mid){
        for(i=minRight; i<=right; i++){
            sorted[sortedIndex++] = list[i];
        }
    }
    else{
        for(i=minLeft; i<=mid; i++){
            sorted[sortedIndex++] = list[i];
        }
    }

    // '결과배열'의 값을 list 배열에 저장해주기(다음 상위 계산에 써야함)
    for(i=left; i<=right; i++){
        list[i] = sorted[i];
    }
}

// merge sort(배열, 시작 index, 끝 index)
void merge_sort(int list[], int left, int right){
    int mid;

    if(left < right){
        // divide
        mid = (left + right) / 2;

        // conquer left
        merge_sort(list, left, mid);
        // conquer right
        merge_sort(list, mid+1, right);

        // combine
        merge(list, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    int list[n];

    for(int i=0; i<n; i++){
        cin >> list[i];
    }

    // using STL
    // sort(list, list+n);

    // merge sort(배열, 배열의 시작, 끝)
    merge_sort(list, 0, n-1);

    print_vector(list, n);
    return 0;
}