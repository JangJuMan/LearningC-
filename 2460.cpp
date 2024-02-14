#include <iostream>

using namespace std;

int main(){
    int people = 0, in, out, max=-1;

    for(int i=0; i<10; i++){
        cin >> out >> in;
        people = people - out + in;
        if(max < people){
            max = people;
        }
    }

    cout << max;

    return 0;
}