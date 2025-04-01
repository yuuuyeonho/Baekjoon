#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N, M;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N >> M;

        int listA[N];
        int listB[M];
        for(int j=0; j<N; j++) {cin >> listA[j];}
        for(int j=0; j<M; j++) {cin >> listB[j];}
 
        sort(listA, listA + N);
        sort(listB, listB + M);

        int cnt=0; 
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(listA[j] > listB[k]){
                    cnt++;
                } else {
                    break;
                }
            }
        }

        cout << cnt << endl;
    }
    
    return 0;
}