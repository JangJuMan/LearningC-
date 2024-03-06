#include <iostream>

using namespace std;

int main(){
    int input[5], min_hambuger=2001, min_drink=2001;
    cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4];
    min_hambuger = min(min(input[0], input[1]), input[2]);
    min_drink = min(input[3], input[4]);
    cout << min_hambuger + min_drink - 50;
    return 0;
}