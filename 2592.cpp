#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    const int SIZE = 10, RANGE = 1000;

    int input, sum=0, max=-1, frqncy=-1;
    int array[RANGE+1] = {0};
    float avg = 0.0f;

    for(int i=0; i<SIZE; i++){
        cin >> input;
        sum += input;
        array[input]++;
        if(max < array[input]){
            max = array[input];
            frqncy = input;
        }
    }
    avg = sum/SIZE;
    cout << avg << endl << frqncy;

    return 0;
}