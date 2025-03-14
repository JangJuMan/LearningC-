// DFS : 1068 트리
// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 51;

int N, leafCnt, deleteNum, rootNode;
vector<int> vec[N_MAX];

int dfs(int num){
    if(num == deleteNum){
        return 1;
    }
    if(vec[num].size() == 0){
        leafCnt++;
        return 0;
    }

    for(int next : vec[num]){
        int isDeleteNum = dfs(next);
        // 자식노드가 1개인데, 그게 delete num으로 사라졌다면, 부모가 leaf node임
        if(isDeleteNum && vec[num].size() == 1){  
            leafCnt++;
        }
    }
    return 0;
}

int main(){
    int input;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &input);
        if(input == -1){
            rootNode = i;
        }
        else{
            vec[input].emplace_back(i);
        }
    }
    scanf("%d", &deleteNum);

    dfs(rootNode);
    
    printf("%d", leafCnt);
    return 0;
}