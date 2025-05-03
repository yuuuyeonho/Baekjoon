#include<iostream>
#include<math.h>
using namespace std;

int num[501][501] = {0};
int dp[501][501] = {0};

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int tmp;
            cin >> tmp;
            num[i][j] = tmp;
        }
    }

    dp[1][1] = num[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + num[i][j];
        }
    }

    int max = 0;

    for(int j=1; j<=n; j++){
        if(max<dp[n][j]) max = dp[n][j];
    }

    cout << max;

    return 0;
}