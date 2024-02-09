#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int M, N;
    cin >> M >> N;

    vector<bool> v(N+1, true);
    v[1] = false;

    for(int i=2; i*i<=N; ++i){
        if(v[i]){
            for(int k=i*i; k<=N; k+=i){
                if(v[k] == false) continue;
                else v[k] = false;
            }
        }
    }   
    
    for(int i=M; i<=N; ++i){
        if(v[i]) cout << i << '\n';
    }
    return 0;
}