#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int child[N];
    int odd[N-1];
    int i, sum=0;
    for(int i=0; i<N; ++i) cin >> child[i];
    
    for(int i=0; i<N-1; ++i){
        odd[i] = child[i+1] - child[i];
    }
    sort(odd, odd+(N-1));
    
    for(int i = 0; i < N-K; ++i) sum += odd[i];
    
    cout << sum;
    
}

/* 
정렬된 원생들 사이의 키의 차이를 구해서 새로 배열을 만들고(여기서 odd) odd 배열을 크기순으로 정렬한다.
나누는 지점이 될 값이 큰 순으로 k-1개를 빼고 나머지를 더해서 구했다.
*/