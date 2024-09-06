#include <iostream>
#include <string>
#include <vector>
#define BASE 60
#define ASCII_ZERO 48

using namespace std;

int time_to_int(string time){
    return (time[0]-ASCII_ZERO)*10*BASE + (time[1]-ASCII_ZERO)*1*BASE + (time[3]-ASCII_ZERO)*10 + time[4]-ASCII_ZERO;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    int int_video_len = time_to_int(video_len);
    int int_pos = time_to_int(pos);
    int int_op_start = time_to_int(op_start);
    int int_op_end = time_to_int(op_end);
    
    for(string cmd : commands){
        if((int_op_start <= int_pos) && (int_pos <= int_op_end)){
            int_pos = int_op_end;
        } 
         
        if(cmd == "prev"){
            int_pos -= 10;
        }
        else if(cmd == "next"){
            int_pos += 10;
        }
        
        if(int_pos < 0){
            int_pos = 0;
        }
        else if((int_op_start <= int_pos) && (int_pos <= int_op_end)){
            int_pos = int_op_end;
        }
        else if(int_video_len < int_pos){
            int_pos = int_video_len;
        }
    }
    
    int int_pos_M = int_pos / BASE;
    string pos_M = "";
    if(int_pos_M < 10){
        pos_M = '0' + to_string(int_pos_M);
    }
    else{
        pos_M = to_string(int_pos_M);
    }
    
    int int_pos_S = int_pos % BASE;
    string pos_S = "";
    if(int_pos_S < 10){
        pos_S = '0' + to_string(int_pos_S);
    }
    else{
        pos_S = to_string(int_pos_S);
    }
    
    answer = pos_M + ":" + pos_S;
    
    return answer;
}