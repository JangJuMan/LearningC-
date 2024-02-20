#include <iostream>

using namespace std;

int main(){
    int seq[1001] = {0};
    int from, to, sum=0, idx=1, j, k=1;

    cin >> from >> to;

    while(idx<1001){
        for(j=1; j<=k; j++){
            seq[idx] = k;
            idx++;
            if(idx>=1001){
                break;
            }
        }
        k++;
    }

    for(idx=from; idx<=to; idx++){
        sum += seq[idx];
    }
    cout << sum;

    return 0;
}

