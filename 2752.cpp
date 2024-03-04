#include <iostream>
#include <algorithm>

using namespace std;

// sort 내가 편한방법
void ver1(){
    int arr[3] = {0};

    for(int i=0; i<3; i++){
        cin >> arr[i];
    }

    sort(arr, arr+3);
    for(int i=0; i<3; i++){
        cout << arr[i] << " ";
    }
}

// if. 코드는 길어져도 연산은 짧아지지 않을까?
void ver2(){
    int arr[3] = {0};

    for(int i=0; i<3; i++){
        cin >> arr[i];
    }

    if(arr[1] < arr[0]){            // 1 0 의 순서
        if(arr[2] < arr[1]){        // 2 1 0 | [2]가 가장 작을 경우
            printf("%d %d %d", arr[2], arr[1], arr[0]);
        }
        else if(arr[0] < arr[2]){   // 1 0 2 | [2]가 가장 클 경우
            printf("%d %d %d", arr[1], arr[0], arr[2]);
        }
        else{                       // 1 2 0 | [2]가 중간에 낄 경우
            printf("%d %d %d", arr[1], arr[2], arr[0]);
        }
    }
    else{                           // 0 1 의 순서
        if(arr[2] < arr[0]){        // 2 0 1 | [2]가 가장 작을 경우
            printf("%d %d %d", arr[2], arr[0], arr[1]);
        }
        else if(arr[1] < arr[2]){   // 0 1 2 | [2]가 가장 클 경우
            printf("%d %d %d", arr[0], arr[1], arr[2]);
        }
        else{                       // 0 2 1 | [2]가 중간에 낄 경우
            printf("%d %d %d", arr[0], arr[2], arr[1]);
        }
    }
}

int main(){
    // ver1();
    ver2();
    return 0;
}