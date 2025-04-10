// 스택 : 에디터
// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<char> left;
    stack<char> right;
    int N;
    char type, ch;
    string str;

    cin >> str;
    for(int i=0; i<str.size(); i++){
        left.emplace(str[i]);
    }
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> type;
        switch(type){
            case 'L':
                if(!left.empty()){
                    right.emplace(left.top());
                    left.pop();
                }
                break;
            case 'D':
                if(!right.empty()){
                    left.emplace(right.top());
                    right.pop();
                }
                break;
            case 'B':
                if(!left.empty()){
                    left.pop();
                }
                break;
            case 'P':
                cin >> ch;
                left.emplace(ch);
                break;
        }
    }

    while(!left.empty()){
        right.emplace(left.top());
        left.pop();
    }

    while(!right.empty()){
        cout << right.top();
        right.pop();
    }

    return 0;
}