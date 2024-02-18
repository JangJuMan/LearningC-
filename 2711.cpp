#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, mis_idx;
    string input;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> mis_idx >> input;
        input.erase(mis_idx-1, 1);
        cout << input << endl;
    }
    
    return 0;
}