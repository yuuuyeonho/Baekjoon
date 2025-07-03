#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int Test_Case = 1; Test_Case <= T; Test_Case++) {
    int n;
    cin >> n;
    int scores[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
      cin >> scores[i];
      max += scores[i];
    }
    int dp[max + 1];
    for (int i = 0; i < max + 1; i++) {
      dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
      int score = scores[i];
      for (int j = max; j >= 0; j--) {
        if (dp[j] == 1) {
          dp[j + score] = 1;
          // cout << j << " + " << score << " = 1\n";
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i <= max; i++) {
      if (dp[i] == 1) {
        // cout << i << " ";
        cnt++;
      }
    }

    cout << "#" << Test_Case << " " << cnt << '\n';
  }

  return 0;
}