#include <iostream>
#include <unordered_set>
using namespace std;

int board[4][4];
unordered_set<int> us;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt, int seven_num) {
  seven_num = seven_num * 10 + board[x][y];
  cnt++;
  if (cnt == 7) {
    us.insert(seven_num);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
    dfs(nx, ny, cnt, seven_num);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int Test_Case = 1; Test_Case <= t; Test_Case++) {
    us.clear();

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> board[i][j];
      }
    }

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        dfs(i, j, 0, 0);
      }
    }

    cout << "#" << Test_Case << " " << us.size() << '\n';
  }
  return 0;
}