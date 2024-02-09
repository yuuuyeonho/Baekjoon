#include<iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    int result=0;
    vector<bool> v(N+1, true);

    for(int i=2; i<=N; ++i){
        if(v[i]){
            cnt++;
            if(cnt == K) result = i;
            for(int k=i*i; k<=N; k+=i){
                if(v[k] == false) continue;
                cnt++;
                if(cnt == K) result = k;
                v[k] = false;
            }
        }
    }

    cout << result;
    return 0;
}