#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T, i, score[5]={0};
    cin >> T;

    while(T--){
        for(i=0; i<5; i++){
            cin >> score[i];
        }
        sort(score, score+5);
        if(score[3] - score[1] >= 4){
            cout << "KIN" << endl;
        }
        else{
            cout << score[1] + score[2] + score[3] << endl;
        }
        
    }
    return 0;
}