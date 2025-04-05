// 구현 : 소용돌이 예쁘게 출력하기
// https://www.acmicpc.net/problem/1022
#include <iostream>
#include <array>

using namespace std;

const int R_MAX = 50, C_MAX = 5;

int r1, c1, r2, c2;
int cnt = 1;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
array<array<int, C_MAX>, R_MAX> arr;

bool isInside(int row, int col){
    return r1 <= row && row <= r2 && c1 <= col && col <= c2;
}

void makeArr(){
    if(isInside(0, 0)){
        arr[-r1][-c1] = cnt;
    }
    cnt++;

    int row=0, col=0, dir=0, curLen=0, len=1;
    while(arr[0][0] == 0 || arr[r2-r1][0] == 0
            || arr[0][c2-c1] == 0 || arr[r2-r1][c2-c1] == 0){
        row += dr[dir];
        col += dc[dir];
        if(isInside(row, col)){
            arr[row - r1][col - c1] = cnt;
        }
        cnt++;
        curLen++;
        
        if(curLen == len){
            curLen = 0;
            dir = (dir + 1) % 4;
            if(dir%2 == 0){
                len++;
            }
        }
    }
}

void printArr(){
    int space = 0;
    while(cnt != 0){
        cnt /= 10;
        space++;
    }

    for(int i=0; i<=r2-r1; i++){
        for(int j=0; j<=c2-c1; j++){
            printf("%*d ", space, arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    makeArr();
    
    printArr();
    
    return 0;
}
