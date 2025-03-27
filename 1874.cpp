#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<char> ans;
    ans.reserve(2*n);
    
    int input, num=1;   // 이렇게 푸는건 참 신기하네... 생각을 잘 못하것다
    stack<int> st;
    while(n--){
        scanf("%d", &input);
        if(!st.empty() && st.top() > input){
            printf("NO");
            return 0;
        } 
        else if(!st.empty() && st.top() == input){
            st.pop();
            ans.emplace_back('-');
        }
        else{
            while(num <= input){
                st.emplace(num++);
                ans.emplace_back('+');
            }
            st.pop();
            ans.emplace_back('-');
        }
    }
    for(char c : ans){
        printf("%c\n", c);
    }
      
   

    // for(int i=0; i<n; i++){
    //     scanf("%d", &nums[i]);
    // }

    // stack<int> st;
    // for(int i=1, numIdx=0; i<=n+1 && numIdx < n;){
    //     if(st.empty()){
    //         st.emplace(i++);
    //         ans.emplace_back('+');
    //         continue;
    //     }
    //     if(st.top() == nums[numIdx]){
    //         st.pop();
    //         ans.emplace_back('-');
    //         numIdx++;
    //     }
    //     else{
    //         st.emplace(i++);
    //         ans.emplace_back('+');
    //     }
    // }
    
    // if(st.empty()){
    //     for(char c : ans){
    //         printf("%c\n", c);
    //     }
    // }
    // else{
    //     printf("NO");
    // }
    return 0;
}