#include <iostream>

using namespace std;

int main(){
    int size, a, min=1000001, max=1;
    cin >> size;
    for(int i=0; i<size; i++){
        cin >> a;
        if(a < min){
            min = a;
        }
        if(a > max){
            max = a;
        }
    }
    cout << min * max;
    
    return 0;
}