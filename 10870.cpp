#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, fibonacci[21] = {0};
    cin >> n;

    fibonacci[1] = 1;
    for(int i=2; i<=n; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    cout << fibonacci[n];
    return 0;
}