#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector 내용 출력
void print_vector(vector<pair<int, int>> input_vector){
    for(pair<int, int> itr : input_vector){
        cout << itr.first << " " << itr.second << endl;
    }
    return;
}

// 두번째 원소 기준으로 정렬
bool compare(const pair<int, int>&a, const pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int SIZE=8, input, sum=0;
    vector<pair<int, int>> arr(8, make_pair(0, 0));

    for(int i=0; i<SIZE; i++){
        cin >> input;
        arr[i].first = i+1;
        arr[i].second = input;
    }

    sort(arr.begin(), arr.end(), compare);
    sort(arr.begin()+(SIZE-5), arr.end());
    // print_vector(arr);
    
    for(int i=SIZE-5; i<SIZE; i++){
        sum += arr[i].second;
    }
    cout << sum << endl;
    for(int i=SIZE-5; i<SIZE; i++){
        cout << arr[i].first << " ";
    }

    
    return 0;
}