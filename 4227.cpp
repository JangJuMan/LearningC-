// 큐 : Ferry Loading IV
// https://www.acmicpc.net/problem/4272
#include <iostream>
#include <queue>

using namespace std;

const int LEFT=0, RIGHT=1;
int T, L, M, carLen;
string whichSide;
queue<int> qL;
queue<int> qR;

void clearQ(){
    while(!qL.empty()){
        qL.pop();
    }
    while(!qR.empty()){
        qR.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> L >> M;
        L *= 100; // m --> cm
        for(int i=0; i<M; i++){     // Get Input
            cin >> carLen >> whichSide;
            if(whichSide[0] == 'l'){
                qL.emplace(carLen);
            }
            else{
                qR.emplace(carLen);
            }
        }

        int moveCount=0;
        int ferryPos = LEFT;
        while(M > 0){
            int ferryCapacity=L;
            if(ferryPos == LEFT){
                while(!qL.empty()){
                    if(ferryCapacity >= qL.front()){
                        ferryCapacity -= qL.front();
                        qL.pop();
                        M--;
                    }
                    else{
                        break;
                    }
                }
                ferryPos = RIGHT;
            }
            else{
                while(!qR.empty()){
                    if(ferryCapacity >= qR.front()){
                        ferryCapacity -= qR.front();
                        qR.pop();
                        M--;
                    }
                    else{
                        break;
                    }
                }
                ferryPos = LEFT;
            }
            moveCount++;
        }
        cout << moveCount << "\n";
        clearQ();
    }
    return 0;
}