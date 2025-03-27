#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    stack<int> st;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            st.emplace(-1);
        }
        else if(s[i] == ')'){
            int len = 0;
            while(st.top() != -1){
                len += st.top();
                st.pop();
            }
            st.pop();
            len *= st.top();
            st.pop();
            st.emplace(len);
        }
        else{
            if(s[i+1] == '('){
                st.emplace(s[i] - '0');
            }
            else{
                st.emplace(1);
            }
        }
    }
    int ans = 0;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    printf("%d", ans);
    
    return 0;
}