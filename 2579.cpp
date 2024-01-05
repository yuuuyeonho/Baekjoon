#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* stairs = new int[n+1];
    
    for(int i=1; i<n+1; ++i){
        cin >> stairs[i];
    }
    int dp[n+1];
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = dp[1]+stairs[2];
    int i = 3;
    while(i<n+1){
        dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
        i++;
    }
    cout << dp[n] << endl;;


    delete[] stairs;
}