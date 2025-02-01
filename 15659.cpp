#include <iostream>
#include <stack>
#define N_MAX 12
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

int opKinds[4];
int numbers[N_MAX];
int opers[N_MAX];
int ansMax = MIN;
int ansMin = MAX;
int N;
stack<int> numStack;
stack<int> opStack;

int calc(int l, int r, int op){
    switch (op){
        case 0:
            return l + r;
        case 1:
            return l - r;
        case 2:
            return l * r;
        case 3:
            return l / r;
    }
}

int getResult(){
    int priority[4] = {0, 0, 1, 1};     // +, -, *, /

    for(int i=0; i<N; i++){
        numStack.push(numbers[i]);
        if(i < N-1){                    // i == N인 경우는 숫자만 스택에 추가하고 종료하도록
            if(opStack.empty()){        // 연산자 스택에 연산자가 없다면, 연산자 push 후 종료
                opStack.push(opers[i]);
            }
            else{
                // opStack != null이고, opStack.top() 연산자의 우선순위가 더 높거나 같을때까지 반복
                while(!opStack.empty() && (priority[opStack.top()] >= priority[opers[i]])){
                    int right = numStack.top();
                    numStack.pop();
                    int left = numStack.top();
                    numStack.pop();
                    int result = calc(left, right, opStack.top());
                    numStack.push(result);
                    opStack.pop();
                }
                opStack.push(opers[i]);
            }
        }
    }
    // 남은 연산자들을 계산
    while(!opStack.empty()){
        int right = numStack.top();
        numStack.pop();
        int left = numStack.top();
        numStack.pop();
        int result = calc(left, right, opStack.top());
        numStack.push(result);
        opStack.pop();
    }
    return numStack.top();
}

void dfs(int depth){
    if(depth == N-1){
        int result = getResult();
        ansMax = max(ansMax, result);
        ansMin = min(ansMin, result);
        return;
    }

    for(int i=0; i<4; i++){
        if(opKinds[i] > 0){
            opKinds[i]--;
            opers[depth] = i;
            dfs(depth+1);
            opKinds[i]++;
        }
    }
}

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }
    for(int j=0; j<4; j++){
        cin >> opKinds[j];
    }
}

int main(){
    init();
    dfs(0);
    printf("%d\n%d", ansMax, ansMin);
    return 0;
}