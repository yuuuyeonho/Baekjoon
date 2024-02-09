#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long dp[1001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int i=3;
    while(i<=n){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i]%10007;
        i++;
    }

    cout << dp[n];
}
// 2*n 타일링 문제. dp[i]는 (dp[i-1]에 2*1한개 붙인거) + (dp[i-2]에 1*2두개쌓은거 붙인거) 로 생각하면 피보나치랑 똑같은 규칙이 나온다.