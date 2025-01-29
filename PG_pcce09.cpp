#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

vector<int> wallet = {30, 15};
vector<int> bill = {26, 17};

int main(){
    int answer = 0;
    int bill_min, bill_max, wallet_min, wallet_max;
    
    while(1){
        bill_min = bill[0] < bill[1] ? bill[0] : bill[1];
        bill_max = bill[0] > bill[1] ? bill[0] : bill[1];
        wallet_min = wallet[0] < wallet[1] ? wallet[0] : wallet[1];
        wallet_max = wallet[0] > wallet[1] ? wallet[0] : wallet[1];
        
        if(bill_min <= wallet_min && bill_max <= wallet_max){
            break;
        }
        
        if(bill[0] > bill[1]){
           bill[0] /= 2; 
        }
        else{
            bill[1] /=2;
        }
        answer++;
        
    }
    return answer;
}