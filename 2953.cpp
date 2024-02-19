#include <iostream>

using namespace std;

int main(){
    int n, sum=0, max=0, winner;
    for(int i=1; i<=5; i++){
        for(int j=0; j<4; j++){
            cin >> n;
            sum += n;
            if(max < sum){
                max = sum;
                winner = i;
            }
        }
        sum = 0;
    }

    cout << winner << " " << max;
    return 0;
}