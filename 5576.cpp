#include <bits/stdc++.h>

using namespace std;

// O(NlogN)
void ver1(){
    // W : 0~9, K : 10~19
    int score[20] = {0};
    for(int i=0; i<20; i++){
        cin >> score[i];
    }
    sort(score+0, score+10);
    sort(score+10, score+20);

    cout << score[9] + score[8] + score[7] << " " << score[19] + score[18] + score[17];
}

// O(N)
void ver2(){
    int sum[2]={0}, max1, max2, max3, input;
    for(int i=0; i<2; i++){
        max1 = max2 = max3 = 0;
        for(int j=0; j<10; j++){
            cin >> input;
            if(max1 < input){
                max3 = max2;
                max2 = max1;
                max1 = input;
            }
            else if(max2 < input){
                max3 = max2;
                max2 = input;
            }
            else if(max3 < input){
                max3 = input;
            }
        }
        sum[i] = max1 + max2 + max3;
    }
    cout << sum[0] << " " << sum[1];
}

int main(){
    // ver1();
    ver2();
    return 0;
}