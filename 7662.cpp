// Priority Queue : 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int T, k, num;
char type;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
map<int, int> mp;

void printForDebug(){
    printf("max Heap : ");
    if(maxHeap.empty()){
        printf("EMPTY");
    }
    else{
        printf("%d", maxHeap.top());
    }

    printf("\tmin Heap : ");
    if(minHeap.empty()){
        printf("EMPTY");
    }
    else{
        printf("%d", minHeap.top());
    }
    printf("\n[MAP]\n");
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        printf("[%d, %d] -> ", itr->first, itr->second);
    }
    printf("\n");
}

void sync(){
    while(!maxHeap.empty() && mp[maxHeap.top()] == 0){
        maxHeap.pop();
    }
    while(!minHeap.empty() && mp[minHeap.top()] == 0){
        minHeap.pop();
    }
}

void deleteMin(){
    if(!minHeap.empty()){
        mp[minHeap.top()]--;
        minHeap.pop();
    }
}

void deleteMax(){
    if(!maxHeap.empty()){
        mp[maxHeap.top()]--;
        maxHeap.pop();
    }
}

void insert(int num){
    maxHeap.emplace(num);
    minHeap.emplace(num);
    mp[num]++;     // map은 이렇게도 사용할 수 있다.
}

void init(){
    mp.clear();
    while(!maxHeap.empty()){
        maxHeap.pop();
    }
    while(!minHeap.empty()){
        minHeap.pop();
    }
}

int main(){
    scanf("%d ", &T);
    for(int i=0; i<T; i++){
        init();
        scanf("%d ", &k);
        for(int j=0; j<k; j++){
            scanf(" %c %d\n", &type, &num);   // 안돌아가면 cin 버전으로 바꿔서 해보세요
            // cin >> type >> num;
            if(type == 'I'){
                insert(num);
            }
            else if(type == 'D'){
                if(num == 1){
                    deleteMax();
                }
                else if(num == -1){
                    deleteMin();
                }
                sync();
            }
            // printForDebug();
        }

        if(maxHeap.empty() || minHeap.empty()){
            printf("EMPTY\n");
        }
        else{
            printf("%d %d\n", maxHeap.top(), minHeap.top());
        }
    }
    return 0;
}