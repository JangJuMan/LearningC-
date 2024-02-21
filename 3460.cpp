#include <iostream>

using namespace std;

int main(){
    int N, T, location;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        location = 0;
        while(N){
            if(N%2 == 1){
                cout << location << " ";
            }
            location++;
            N/=2;
        }
        cout << endl;
    }

    return 0;
}