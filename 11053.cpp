#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int num[N];
    int dp[N];
    for(int i=0; i<N; i++){
        cin >> num[i];
        dp[i] = 1; 
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(num[i] > num[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    int max = 0;
    for(int i=0; i<N; i++){
        if(dp[i] > max) max = dp[i];
    }

    cout << max;

    return 0;
}