#include <iostream>

using namespace std;

struct DATA{
    int r1, r2, b1, b2, count;
};

DATA start;
char map[10][10];
const int d1[] = {-1, 1, 0, 0};
const int d2[] = {0, 0, -1, 1};


int dfs(DATA curr){
    // printf("VISIT(count : %d) : R[%d][%d], B[%d][%d]\n", curr.count, curr.r1, curr.r2, curr.b1, curr.b2);
    if(curr.count > 10){
        // cout << "return -1(count>10)" << endl;
        return -1;
    }
    if(map[curr.b1][curr.b2] == 'O'){
        // cout << "return -1(blue goal)" << endl;
        return -1;
    }
    else if(map[curr.r1][curr.r2] == 'O'){
        // cout << "return[count] = " << curr.count << endl;
        return curr.count;
    }

    int cnt[4] = {0};

    // 기울이기(상 하 좌 우)
    for(int dir=0; dir<4; dir++){
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

        // 유의미한 변화가 있다면 dfs ㄱㄱ(중복있음;;)
        // (사실 visited로 하고 싶었는데, 최단거리가 있는데 이미 방문했다는 이유로 체크를 안해버림;;)
        if(next_r1 != curr.r1 || next_r2 != curr.r2 || next_b1 != curr.b1 || next_b2 != curr.b2){
            DATA next;
            next.r1 = next_r1;
            next.r2 = next_r2;
            next.b1 = next_b1;
            next.b2 = next_b2;
            next.count = curr.count + 1;
            cnt[dir] = dfs(next);
        }
        else{
            cnt[dir] = -1;
        }
    }

    int min = 11;
    if(cnt[0] == -1 && cnt[1] == -1 && cnt[2] == -1 && cnt[3] == -1){
        min = -1;
    }
    else{
        for(int i=0; i<4; i++){
            // printf("cnt[%d] : %d\n", i, cnt[i]);
            if(cnt[i] != -1 && min > cnt[i]){
                min = cnt[i];
            }
        }
    }
    return min;
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                start.r1 = i; 
                start.r2 = j;
            }
            if(map[i][j] == 'B'){
                start.b1 = i;
                start.b2 = j;
            }
        }
    }
    start.count = 0;

    int res = dfs(start);
    cout << res;

    return 0;
}