#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int sum=0;
    vector<int> input(5, 0);
    for(int i=0; i<5; i++){
        cin >> input[i];
        sum += input[i];
    }
    sort(input.begin(), input.end());
    printf("%d\n%d", sum/5, input[2]);
    return 0;
}