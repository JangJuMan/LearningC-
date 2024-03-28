#include <iostream>
#include <queue>

using namespace std;

// 현재 숫자, 이 숫자까지 오는데 걸리는 거리
struct DATA{
    int num, count;
};

// 최초값
DATA start;

int bfs(int x){
    // 첨부한 사진과 같은 DP 표 작성, visited, 횟수
    int map[4][x+1] = {0}, visited[x+1] = {0}, count=0;
    // {3, 2}으로 나눠지면 나눈 값, 아니면 -1
    for(int i=x; i>=0; i--){
        map[1][i] = i-1;
        map[2][i] = (i%2 == 0) ? i/2 : -1;
        map[3][i] = (i%3 == 0) ? i/3 : -1;
    }

    // 큐 생성, 초기값 세팅
    queue<DATA> q;
    q.push(start);
    visited[x] = 1;

    // BFS 반복
    while(!q.empty()){
        DATA curr = q.front();
        q.pop();
        // 1을 만난 경우, 걸린 횟수 저장 후 탈출
        if(curr.num == 1){
            count = curr.count;
            break;
        }
        
        // -1, /2, /3의 값이 저장된 표 = map[][]
        for(int i=1; i<=3; i++){
            if(map[i][curr.num] != -1){
                if(visited[map[i][curr.num]] == 0){
                    // printf("VISIT[%d] / count = [%d]\n", map[i][curr.num], curr.count);
                    visited[map[i][curr.num]] = 1;
                    DATA next;
                    next.num = map[i][curr.num];
                    next.count = curr.count + 1;
                    q.push(next);
                }
            }
        }
    }
    return count;
}

int main(){
    int N, res=0;
    cin >> N;

    start.num = N, start.count = 0;

    res = bfs(N);

    cout << res;

    return 0;
}