#include<iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int *coin = new int[N];
    int tmp, cnt=0;
    for(int i=0; i<N; ++i) cin >> coin[i];
    for(int i=N-1; i>=0; --i){
        cnt += K/coin[i];
        K = K % coin[i];
    }
    cout << cnt << endl;
}