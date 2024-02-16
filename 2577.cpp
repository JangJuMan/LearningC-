#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, b, c, num, cnt[10] = {0};  
    // int 배열 대신 vector로 선언할 수도 있음. vector<int> v(10, 0);
    // vector는 확장기능이 많아서 활용하기 편할 듯. 앞으로 많이 써보자.
    
    cin >> a >> b >> c;
    num = a*b*c;

    while(num){
        cnt[num%10]++;
        num/=10;
    }

    // for each 문 방식
    for(int i : cnt){
        cout << i << endl;
    }

    return 0;
}