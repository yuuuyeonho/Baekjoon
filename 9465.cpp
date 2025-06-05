#include <algorithm>
#include <iostream>
using namespace std;

int sticker[2][100001];

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    int max_score = 0;
    cin >> n;
    int dp[2][n + 1];

    for (int j = 0; j < n; j++) {
      cin >> sticker[0][j];
    }
    for (int j = 0; j < n; j++) {
      cin >> sticker[1][j];
    }

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = dp[1][0] + sticker[0][1];
    dp[1][1] = dp[0][0] + sticker[1][1];

    for (int j = 2; j < n; j++) {
      dp[0][j] = sticker[0][j] + max(dp[1][j - 2], dp[1][j - 1]);
      dp[1][j] = sticker[1][j] + max(dp[0][j - 2], dp[0][j - 1]);
    }

    max_score = max(dp[0][n - 1], dp[1][n - 1]);

    cout << max_score << endl;
  }

  return 0;
}