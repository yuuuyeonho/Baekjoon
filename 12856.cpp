#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<pair<int, int> > vec;
int dp[101][100001];

int main() {
    int n, k;
    cin >> n >> k;
    
    vec.push_back(make_pair(0,0));
    for(int i=1; i<=n; i++){
        int w, v;
        cin >> w >> v;
        vec.push_back(make_pair(w, v));
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(vec[i].first > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], vec[i].second + dp[i-1][j-vec[i].first]);
        }
    }

    cout << dp[n][k];

    return 0;
}