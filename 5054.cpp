#include <iostream>

using namespace std;

int main(){
    int t, n, input, max, min, distance=0;
    cin >> t;
    while(t--){
        cin >> n;
        max = -1;
        min = 100;
        while(n--){
            cin >> input;
            if(max < input){
                max = input;
            }
            if(min > input){
                min = input;
            }
        }
        distance = (max - min)*2;
        cout << distance << endl;
    }
    return 0;
}
