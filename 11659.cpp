#include<iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    int numList[N];
    int sumList[N+1];
    sumList[0] = 0;
    
    for(int i=0; i<N; i++){
        cin >> numList[i];
        sumList[i+1] = sumList[i] + numList[i];
    }

    for(int t=0; t<M; t++){
        int i, j;
        cin >> i >> j;
        int sum = sumList[j] - sumList[i-1];
        cout << sum << '\n';
    }
    
    return 0;
}