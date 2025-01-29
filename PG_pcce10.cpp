#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    bool check = 1;

    sort(mats.begin(), mats.end());
    
    int parkRow = park.size();
    int parkCol = park[0].size();
    
    for(int row=0; row<parkRow; row++){
        for(int col=0; col<parkCol; col++){
            if(park[row][col] == "-1"){
                // printf("park[%d][%d] 확인중\n", row, col);
                for(int matSize : mats){
                    // 현재자리(row, col)의 위치를 포함해서 matSize를 계산해야 하므로 -1 추가
                    if(row + (matSize-1) >= parkRow || col + (matSize-1) >= parkCol){
                        // 범위초과!
                        continue;
                    }
                    
                    check = true;
                    
                    // matSize만큼 주변 자리 확인
                    for(int i=0; i<matSize; i++){
                        for(int j=0; j<matSize; j++){
                            // 빈자리가 아니면 앉지 못함
                            if(park[row+j][col+i] != "-1"){
                                check = false;
                                break;
                            }
                        }
                        if(!check){ // 앉지 못한다고 판단되면 바로 루프 탈출
                            break;
                        }
                    }
                    // 앉을 수 있으면, 현재까지의 최대값과 비교해서 더 큰 값이면 answer에 저장
                    if(check){
                        answer = answer > matSize ? answer : matSize;
                    }
                }
            }
        }
    }
    

    return answer;
}