#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

int moveList[300001];
unordered_set<int> otherSide;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("sample_input2.txt", "r", stdin);

  int t;
  int Test_Case;
  cin >> t;
  for (Test_Case = 1; Test_Case <= t; ++Test_Case) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m - 1; ++i) {
      cin >> moveList[i];
    }

    long long team1num;
    long long team2num;
    long long team1advan;
    long long team2advan;

    if (n % 2 == 0) {  // 총 인원이 짝수인 경우
      team1num = n / 2;
      team2num = team1num;
    } else {  // 총 인원이 홀수인 경우
      team1num = (n + 1) / 2;
      team2num = team1num - 1;
    }
    team1advan = team1num * team1num;
    team2advan = team2num * team2num + team2num;

    for (int i = 0; i < m; ++i) {
      cout << team1advan - team2advan << " ";

      if (i == m - 1) break;
      int whoMove = moveList[i];
      int whoMoveScore;
      if (otherSide.count(whoMove) == 0) {  // 제자리에 있다면
        whoMoveScore = whoMove;
        otherSide.insert(whoMove);  // 반대편으로 감
      } else {
        whoMoveScore = -whoMove;
        otherSide.erase(whoMove);  // 돌아옴
      }

      if (whoMove % 2 == 0) {  // 이동할 사람이 짝수인 경우
        team1advan += (long long)whoMoveScore;
        team2advan -= (long long)whoMoveScore;
      } else {  // 이동할 사람이 홀수인 경우
        team1advan -= (long long)whoMoveScore;
        team2advan += (long long)whoMoveScore;
      }
    }
    otherSide.clear();
    cout << '\n';
    cout.flush();
  }
  return 0;
}