#include <bits/stdc++.h>

#define MIN 0
#define MAX 100

using namespace std;

int main(){
    int K, N, Class, Lgap, gap;
    cin >> K;

    for(Class=1; Class<=K; Class++){
        cin >> N;
        Lgap=0;
        vector<int> score(N, 0);
        for(int j=0; j<N; j++){
            cin >> score[j];
        }
        
        // 내림차순 정렬
        sort(score.begin(), score.end(), greater<int>());

        // Largest gap
        for(int j=1; j<N; j++){
            gap = score[j-1] - score[j];
            if(Lgap < gap){
                Lgap = gap;
            }
        }

        printf("Class %d\nMax %d, Min %d, Largest gap %d\n", Class, score[0], score[N-1], Lgap);
    }

    return 0;
}