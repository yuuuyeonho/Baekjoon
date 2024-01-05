#include<iostream>
using namespace std;

int isprime(int n){
    int half = n/2;
    for(int i=2; i<n; ++i){
        if(n%i == 0)    
            return 0;
    }
    return 1;
}

int main(){
    int N;
    int tmp;
    int cnt = 0;
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> tmp;
        if(tmp == 1) continue;
        else if(tmp == 2){
            cnt++;
            continue;
        }
        else if(isprime(tmp)) cnt++;
    }
    cout << cnt;
}