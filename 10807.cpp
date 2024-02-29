#include <iostream>

using namespace std;

// search & counting
void ver1(){
    int N, v, cnt=0;
    cin >> N;
    int arr[N] = {0};

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> v;

    for(int i : arr){
        if(i == v){
            cnt++;
        }
    }
    cout << cnt << endl;
    return;
}

// using count index
void ver2(){
    int N, v, tmp;
    cin >> N;
    int arr[201] = {0};
    for(int i=0; i<N; i++){
        cin >> tmp;
        arr[tmp+100]++;
    }
    cin >> v;
    cout << arr[v+100] << endl;
    return;
}

int main(){
    // ver 1
    ver1();

    // ver 2
    ver2();

    return 0;
}