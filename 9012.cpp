// Binary Search : 수찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <stack>

using namespace std;

stack<char> st;
bool check;

void init(){
    while(!st.empty()){
        st.pop();
    }
    check = true;
}

int main(){
    int T;
    string input;

    scanf("%d", &T);
    while(T--){
        cin >> input;
        init();
        for(int i=0; i<input.size(); i++){
            if(input[i] == ')'){
                if(st.empty()){
                    check = false;
                    break;
                }
                st.pop();
            }
            else{
                st.emplace(input[i]);
            }
        }
        if(!st.empty()){
            check = false;
        }
        if(check){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}