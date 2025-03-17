// divide and conquer : Z
// https://www.acmicpc.net/problem/1074
#include <iostream>
#include <cmath>

using namespace std;

int N, r, c, cnt;

bool isInside(int row, int col, int len){
    return row <= r && r < row + len && col <= c && c < col + len;
}

void divide(int row, int col, int len){
    if(row == r && col == c){
        printf("%d", cnt);
        return;
    }
    else if(isInside(row, col, len)){
        divide(row, col, len/2);
        divide(row, col + len/2, len/2);
        divide(row + len/2, col, len/2);
        divide(row + len/2, col + len/2, len/2);
    }
    else{
        cnt += (len * len);
    }
}

int main(){
    scanf("%d %d %d", &N, &r, &c);
    divide(0, 0, pow(2, N));
    return 0;
}