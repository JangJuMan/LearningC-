// 코드가 너무 길어진다 + 나도 헷갈려서 중간에 꼬인 경우가 많았음.

#include <iostream>

using namespace std;

int N, M, Goal[2];
char map[11][11];

// 기울였을 때 멈추는 좌표리턴
int lean_left(int obj1, int obj2, int another1, int another2){
    int res;
    for(res=obj2; res>=0; res--){
        if(map[obj1][res-1] == '#'){ // 왼쪽이 벽이면 멈춘다
            break;
        }
        else if(obj1 == another1 && res-1 == another2){ // 왼쪽이 다른 구슬이면 멈춘다
            break;
        }
        else if(map[obj1][res] == 'O'){ // 구멍을 만나면 멈춘다
            break;
        }
    }
    // printf("\t[lean left] : obj[%d][%d]--> [%d][%d], ano[%d][%d] \n", obj1, obj2, obj1, res, another1, another2);
    return res;
}

int lean_right(int obj1, int obj2, int another1, int another2){
    int res;
    for(res=obj2; res<M; res++){
        if(map[obj1][res+1] == '#'){ // 오른쪽이 벽이면 멈춘다
            break;
        }
        else if(obj1 == another1 && res+1 == another2){ // 오른쪽이 다른 구슬이면 멈춘다
            break;
        }
        else if(map[obj1][res] == 'O'){ // 구멍을 만나면 멈춘다
            break;
        }
    }
    // printf("\t[lean right] : obj[%d][%d]--> [%d][%d], ano[%d][%d] \n", obj1, obj2, obj1, res, another1, another2);
    return res;
}

int lean_top(int obj1, int obj2, int another1, int another2){
    int res;
    for(res=obj1; res>=0; res--){
        if(map[res-1][obj2] == '#'){ // 위쪽이 벽이면 멈춘다
            break;
        }
        else if(res-1 == another1 && obj2 == another2){ // 위쪽이 다른 구슬이면 멈춘다
            break;
        }
        else if(map[res][obj2] == 'O'){ // 구멍을 만나면 멈춘다
            break;
        }
    }
    // printf("\t[lean top] : obj[%d][%d]--> [%d][%d], ano[%d][%d] \n", obj1, obj2, res, obj2, another1, another2);
    return res;
}

int lean_bottom(int obj1, int obj2, int another1, int another2){
    int res;
    for(res=obj1; res<N; res++){
        if(map[res+1][obj2] == '#'){ // 아래쪽이 벽이면 멈춘다
            break;
        }
        else if(res+1 == another1 && obj2 == another2){ // 아래쪽이 다른 구슬이면 멈춘다
            break;
        }
        else if(map[res][obj2] == 'O'){ // 구멍을 만나면 멈춘다
            break;
        }
    }
    // printf("\t[lean bottom] : obj[%d][%d]--> [%d][%d], ano[%d][%d] \n", obj1, obj2, res, obj2, another1, another2);
    return res;
}




int find_way(int r1, int r2, int b1, int b2, int count){
    // printf("FINDing...(try: %d) BLUE[%d][%d]\tRED[%d][%d]\n", count, b1, b2, r1, r2);
    if(count > 10){
        // cout << "return -1(count > 10)" << endl;
        return -1;
    }
    else if(b1 == Goal[0] && b2 == Goal[1]){
        // cout << "return -1(blue goals)" << endl;
        return -1;
    }
    else if(r1 == Goal[0] && r2 == Goal[1]){ // 이걸 통과한다는 건, 파란공은 구멍에 안들어갔다는 뜻
        // cout << "return ??(red Goals)" << endl;
        return count;
    }

    int cnt[4] = {0};
    int newR1, newR2, newB1, newB2;
    
    // 왼쪽으로 기울이기
    if(b2 < r2){  // 파란공이 왼쪽에 있으면, 파란공 먼저
        newB2 = lean_left(b1, b2, r1, r2);
        if(b1 == Goal[0] && newB2 == Goal[1]){ // 파란공이 구멍에 들어가면 치워주기(사실 파란공 들어간 순간 실패라 의미는 없음)
            newR2 = lean_left(r1, r2, b1, -1);
        }
        else{  // 파란공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newR2 = lean_left(r1, r2, b1, newB2);
        }
    }
    else{  // 빨간공이 왼쪽에 있으면, 빨간공 먼저
        newR2 = lean_left(r1, r2, b1, b2);
        if(r1 == Goal[0] && newR2 == Goal[1]){ // 빨간공이 구멍에 들어가면 치워주기
            newB2 = lean_left(b1, b2, r1, -1);
        }
        else{  // 빨간공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newB2 = lean_left(b1, b2, r1, newR2);
        }
    }
    // 왼쪽으로 기울였을때, 변화가 있으면 recursive call을 한다.
    if(newR2 != r2 || newB2 != b2){
        cnt[0] = find_way(r1, newR2, b1, newB2, count+1);
        // printf("CNT[0] : %d\n", cnt[0]);
    }
    else{
        cnt[0] = -1;
    }
    
    // 오른쪽으로 기울이기
    if(b2 > r2){  // 파란공이 오른쪽에 있으면, 파란공 먼저
        newB2 = lean_right(b1, b2, r1, r2);
        if(b1 == Goal[0] && newB2 == Goal[1]){ // 파란공이 구멍에 들어가면 치워주기(사실 파란공 들어간 순간 실패라 의미는 없음)
            newR2 = lean_right(r1, r2, b1, -1);
        }
        else{  // 파란공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newR2 = lean_right(r1, r2, b1, newB2);
        }
    }
    else{  // 빨간공이 오른쪽에 있으면, 빨간공 먼저
        newR2 = lean_right(r1, r2, b1, b2);
        if(r1 == Goal[0] && newR2 == Goal[1]){ // 빨간공이 구멍에 들어가면 치워주기
            newB2 = lean_right(b1, b2, r1, -1);
        }
        else{  // 빨간공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newB2 = lean_right(b1, b2, r1, newR2);
        }
    }
    // 오른쪽으로 기울였을때, 변화가 있으면 recursive call을 한다.
    if(newR2 != r2 || newB2 != b2){
        cnt[1] = find_way(r1, newR2, b1, newB2, count+1);
        // printf("CNT[1] : %d\n", cnt[1]);
    }
    else{
        cnt[1] = -1;
    }

    // 아래쪽으로 기울이기
    if(b1 > r1){  // 파란공이 아래쪽에 있으면, 파란공 먼저
        newB1 = lean_bottom(b1, b2, r1, r2);
        if(newB1 == Goal[0] && b2 == Goal[1]){ // 파란공이 구멍에 들어가면 치워주기(사실 파란공 들어간 순간 실패라 의미는 없음)
            newR1 = lean_bottom(r1, r2, -1, b2);
        }
        else{  // 파란공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newR1 = lean_bottom(r1, r2, newB1, b2);
        }
    }
    else{  // 빨간공이 아래쪽에 있으면, 빨간공 먼저
        newR1 = lean_bottom(r1, r2, b1, b2);
        if(newR1 == Goal[0] && r2 == Goal[1]){ // 빨간공이 구멍에 들어가면 치워주기
            newB1 = lean_bottom(b1, b2, -1, r2);
        }
        else{  // 빨간공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newB1 = lean_bottom(b1, b2, newR1, r2);
        }
    }
    // 아래쪽으로 기울였을때, 변화가 있으면 recursive call을 한다.
    if(newR1 != r1 || newB1 != b1){
        cnt[2] = find_way(newR1, r2, newB1, b2, count+1);
        // printf("CNT[2] : %d\n", cnt[2]);
    }
    else{
        cnt[2] = -1;
    }

    // 위쪽으로 기울이기
    if(b1 < r1){  // 파란공이 위쪽에 있으면, 파란공 먼저
        newB1 = lean_top(b1, b2, r1, r2);
        if(newB1 == Goal[0] && b2 == Goal[1]){ // 파란공이 구멍에 들어가면 치워주기(사실 파란공 들어간 순간 실패라 의미는 없음)
            newR1 = lean_top(r1, r2, -1, b2);
        }
        else{  // 파란공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newR1 = lean_top(r1, r2, newB1, b2);
        }
    }
    else{  // 빨간공이 위쪽에 있으면, 빨간공 먼저
        newR1 = lean_top(r1, r2, b1, b2);
        if(newR1 == Goal[0] && r2 == Goal[1]){ // 빨간공이 구멍에 들어가면 치워주기
            newB1 = lean_top(b1, b2, -1, r2);
        }
        else{  // 빨간공이 구멍에 들어가지 않았다면, 업데이트된 위치로 계산
            newB1 = lean_top(b1, b2, newR1, r2);
        }
    }
    // 아래쪽으로 기울였을때, 변화가 있으면 recursive call을 한다.
    if(newR1 != r1 || newB1 != b1){
        cnt[3] = find_way(newR1, r2, newB1, b2, count+1);
        // printf("CNT[3] : %d\n", cnt[3]);
    }
    else{
        cnt[3] = -1;
    }

    // 최소값 or 불가능(-1) 리턴
    int min = 10;
    if(cnt[0] == -1 && cnt[1] == -1 && cnt[2] == -1 && cnt[3] == -1){
        min = -1;
    }
    else{
        for(int i=0; i<4; i++){
            if(cnt[i] != -1 && min > cnt[i]){
                min = cnt[i];
            }
        }
    }
    // printf("\t min == %d\n\n", min);
    return min;
}


int main(){
    int b1=0, b2=0, r1=0, r2=0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            switch(map[i][j]){
                case 'B' :
                    b1 = i, b2 = j;
                    break;
                case 'R' :
                    r1 = i, r2 = j;
                    break;
                case 'O' :
                    Goal[0] = i, Goal[1] = j;
                    break;
            }
        }
    }
    int result = find_way(r1, r2, b1, b2, 0);
    cout << result;

    return 0;
}