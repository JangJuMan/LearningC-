#include <iostream>

using namespace std;

// 숫자 거꾸로 하기
int reverse(int input){
    int result = 0;

    while(input != 0){
        result *= 10;
        result += input%10;
        input /= 10;
    }

    return result;
}

int main()
{
    int input_a, input_b, reverse_a, reverse_b;
    cin >> input_a >> input_b;
    reverse_a = reverse(input_a);
    reverse_b = reverse(input_b);
    reverse_a > reverse_b ? cout << reverse_a : cout << reverse_b;
    
    return 0;
}

