#include <iostream>
#include <queue>

using namespace std;

struct DATA{
    int r1, r2, b1, b2, count;
};

DATA start;
char map[10][10];

int bfs(){
    const int d1[] = {-1, 1, 0, 0};     // [0] : (-1, 0), [1] : (1, 0), [2] : (0, -1), [3] : (0, 1)
    const int d2[] = {0, 0, -1, 1};     // 상하좌우 방향의 단위벡터

    int visited[10][10][10][10] = {0, };    // 빨간공(r1, r2) 파란공(b1, b2) 좌표
    queue<DATA> q;
    q.push(start);                          // 최초위치 큐에 추가
    visited[start.r1][start.r2][start.b1][start.b2] = 1;  // 최초위치 방문함

    int ret = -1;
    while(!q.empty()){
        DATA curr = q.front();
        q.pop();
        if(curr.count > 10){
            break;
        }
        if(map[curr.r1][curr.r2] == 'O' && map[curr.b1][curr.b2] != 'O'){   // 빨간공만 들어간 경우, 성공
            ret = curr.count;
            break;
        }

        // 상하좌우 방향으로 한번씩 기울이기
        for(int dir = 0; dir < 4; ++dir){
            int next_r1 = curr.r1;
            int next_r2 = curr.r2;
            int next_b1 = curr.b1;
            int next_b2 = curr.b2;

            while(1){ // 빨간공 이동시키기
                if(map[next_r1][next_r2] != '#' && map[next_r1][next_r2] != 'O'){ // 갈 수 있으면 계속 전진
                    next_r1 = next_r1 + d1[dir];
                    next_r2 = next_r2 + d2[dir];
                }
                else{
                    if(map[next_r1][next_r2] == '#'){   // 벽을 만나면 정지(뒤로 한칸 물리기 후 탈출)
                        next_r1 = next_r1 - d1[dir];
                        next_r2 = next_r2 - d2[dir];
                    }
                    break;
                }
            }

            while(1){ // 파란공 이동시키기
                if(map[next_b1][next_b2] != '#' && map[next_b1][next_b2] != 'O'){ // 갈 수 있으면 계속 전진
                    next_b1 = next_b1 + d1[dir];
                    next_b2 = next_b2 + d2[dir];
                }
                else{
                    if(map[next_b1][next_b2] == '#'){   // 벽을 만나면 정지
                        next_b1 = next_b1 - d1[dir];
                        next_b2 = next_b2 - d2[dir];
                    }
                    break;
                }
            }

            // 파란공과 빨간공이 겹치는 경우
            if(next_r1 == next_b1 && next_r2 == next_b2){
                // 구멍인 경우라면 둘다 나가서 실패
                // 구멍이 아닌 경우라면, 겹치지 않도록 조정
                if(map[next_r1][next_r2] != 'O'){
                    // 빨간공이 움직인 거리와 파란공이 움직인 거리 측정
                    // 더멀리서 온 공이 늦게 도착했으므로 한 칸 뒤로 물러야 한다.
                    int red_dist = abs(next_r1 - curr.r1) + abs(next_r2 - curr.r2);     // 기울이는 움직임은 1 or 2번축 하나만 변하므로
                    int blue_dist = abs(next_b1 - curr.b1) + abs(next_b2 - curr.b2);    // 다른 축의 움직임은 어차피 0이 됨(더하여 종합계산)
                    if(red_dist > blue_dist){   // 빨간공이 멀리서 온 경우 -1칸
                        next_r1 = next_r1 - d1[dir];
                        next_r2 = next_r2 - d2[dir];
                    }
                    else{   // 파란 공이 멀리서 온 경우 -1칸
                        next_b1 = next_b1 - d1[dir];
                        next_b2 = next_b2 - d2[dir];
                    }
                }
            }

            // 처음 방문한 곳이라면, 방문기록 업데이트, Q에 추가하기
            if(visited[next_r1][next_r2][next_b1][next_b2] == 0){ 
                visited[next_r1][next_r2][next_b1][next_b2] = 1;
                DATA next;
                next.r1 = next_r1;
                next.r2 = next_r2;
                next.b1 = next_b1;
                next.b2 = next_b2;
                next.count = curr.count + 1;
                q.push(next);
            }
            // else : 이미 방문했던 곳이라면 생략(중복방문 제거)
        }
    }
    return ret;
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){   // 빨간, 파란공의 최초위치 저장
                start.r1 = i; start.r2 = j;
            }
            if(map[i][j] == 'B'){
                start.b1 = i; start.b2 = j;
            }
        }
    }
    start.count = 0;
    
    int result = bfs();
    cout << result;

    return 0;
}