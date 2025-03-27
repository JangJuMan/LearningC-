// stack : 화학식량
// https://www.acmicpc.net/problem/2257
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum = 0, tmp;
    string input;
    cin >> input;

    stack<int> st;
    for(int i=0; i<input.length(); i++){
        switch (input[i]){
            case '(':
                st.emplace(-1);
                break;
            case ')':
                sum = 0;
                while(st.top() != -1){
                    sum += st.top();
                    st.pop();
                }
                st.pop();
                st.emplace(sum);
                break;
            case 'H':
                st.emplace(1);
                break;
            case 'C':
                st.emplace(12);
                break;
            case 'O':
                st.emplace(16);
                break;
            default:
                tmp = st.top() * (input[i] - '0');
                st.pop();
                st.emplace(tmp);
                break;
        }
    }
    sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}