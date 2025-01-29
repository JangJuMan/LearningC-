#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int low, int high) {

    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int bSearch(vector<int> &vec, int target){
    int left = 0;
    int right = vec.size()-1;
    while(left <= right){
        int pivot = (left + right) / 2;
        if(vec[pivot] == target){
            return pivot;
        }
        else if(vec[pivot] < target){
            left = pivot + 1;
        }
        else{
            right = pivot - 1;
        }
    }
    return -1;
}

int pivotIndex(vector<int> &vec){
    int sum = 0;
    for(auto &i : vec){
        sum += i;
    }

    int leftSum = 0;
    int rightSum = sum;
    int pastPivotNum = 0;
    for(int i=0; i<vec.size(); i++){
        int num = vec[i];
        rightSum -= num;
        leftSum += pastPivotNum;

        if(leftSum == rightSum){
            return i;
        }
        pastPivotNum = num;
    }
    return -1;
}

void calcSubset(vector<int>& vec, vector<vector<int>> &res, vector<int>& subset, int idx){
    res.emplace_back(subset);

    for(int i=idx; i<vec.size(); i++){
        subset.emplace_back(vec[i]);

        calcSubset(vec, res, subset, i+1);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& vec){
    vector<int> subset;
    vector<vector<int>> res;
    int idx = 0;
    calcSubset(vec, res, subset, idx);
    return res;
}

void print(vector<int>& vec){
    for(auto i : vec){
        cout << i << endl;
    }
}

void merge(vector<int>& vec, int first, int mid, int last){
    vector<int> sorted(last - first + 1);
    int i, j, k;
    i=first;
    j=mid+1;
    k=0;

    while(i <= mid && j <= last){
        if(vec[i] <= vec[j]){
            sorted[k++] = vec[i++];
        }
        else{
            sorted[k++] = vec[j++];
        }
    }

    if(i > mid){
        while(j <= last){
            sorted[k++] = vec[j++];
        }
    }
    else{
        while(i <= mid){
            sorted[k++] = vec[i++];
        }
    }

    for(i=first, k=0; i <= last; i++, k++){
        vec[i] = sorted[k];
    }
}

void mergeSort(vector<int>& vec, int first, int last){
    if(first < last){
        int mid = (first + last) / 2;
        mergeSort(vec, first, mid);
        mergeSort(vec, mid+1, last);
        merge(vec, first, mid, last);
    }
}

vector<int> n_arr(11);
void countingSort(vector<int>& vec){
    int max_value_tmp = 10;
    vector<int> count(max_value_tmp);

    for(int i=0; i<vec.size(); i++){
        count[vec[i]]++;
    }
    for(int i=1; i<=max_value_tmp; i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i=0; i<vec.size(); i++){
        count[vec[i]]--;
        n_arr[count[vec[i]]] = vec[i];
    }

}


int main() {
    vector<int> vec = {10, 7, 8, 9, 1, 5};
    // int n = vec.size();
    // quickSort(vec, 0, n - 1);
    // for (auto i : vec) {
    //     cout << i << " ";
    // }

    // int a = bSearch(vec, 2);
    // cout << a << endl;

    // vector<int> vec_findPivotIndex = {1, 8, 2, 9, 2, 3, 6};
    // cout << pivotIndex(vec_findPivotIndex) << endl;


    // vector<int> vec_subset = {1, 2, 3};
    // vector<vector<int>> res = subsets(vec_subset);
    // for(int i=0; i<res.size(); i++){
    //     for(int j=0; j<res[i].size(); j++){
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // mergeSort(vec, 0, vec.size()-1);

    countingSort(vec);
    print(vec);

    return 0;
}

void merg(){
    vector<int> sorted(last - first + 1);
    int i, j, k;
    i=first;
    j=mid+1;
    k=0;

    while(i<=mid && j <= last){
        if(vec[i] <= vec[j]){
            sorted[k++] = vec[i++];
        }
        else{
            sorted[k++] = vec[j++];
        }
    }

    if(i > mid){
        while(j <= last){
            sorted[k++] = vec[j++];
        }
    }
    else{
        while(i <= mid){
            sorted[k++] = vec[i++];
        }
    }

    for(i=first, k=0; i<=last; i++, k++){
        vec[i] = sorted[k];
    }
}

void mergS(){
    if(left < right){
        int mid = (left + right)/2;
        mergS(vec, left, mid);
        mergS(vec, mid+1, right);
        merg(vec, first, mid, right);
    }
}