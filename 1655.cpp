// Priority Queue : 가운데를 말해요
// https://www.acmicpc.net/problem/1655
// 중간값 : 반띵의 최대 or 반띵의 최소
#include <iostream>
#include <queue>

using namespace std;

int N, input;
priority_queue<int, vector<int>, less<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &input);
        if(maxHeap.empty()){
            maxHeap.emplace(input);
        }
        else if(minHeap.empty()){
            if(maxHeap.top() <= input){
                minHeap.emplace(input);
            }
            else{
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
                maxHeap.emplace(input);
            }
        }
        else{
            maxHeap.emplace(input);
            if(maxHeap.top() > minHeap.top()){
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();

                if(maxHeap.size() < minHeap.size()){
                    maxHeap.emplace(minHeap.top());
                    minHeap.pop();
                }
            }
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
            }
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}