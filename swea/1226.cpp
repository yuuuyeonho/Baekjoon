#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int map[16][16];
pair<int, int> start;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isPossible;
bool isVisited[16][16];

// void dfs(int x, int y) {
//   if (map[x][y] == 3) {
//     isPossible = true;
//     return;
//   }
//   for (int i = 0; i < 4; ++i) {
//     int nx = x + dx[i];
//     int ny = y + dy[i];
//     if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16)
//       continue;
//     else if (map[nx][ny] == 0 || map[nx][ny] == 3) {
//       dfs(nx, ny);
//     }
//   }
//   return;
// }

void bfs() {
  queue<pair<int, int> > q;
  q.push(start);

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    isVisited[cur.first][cur.second] = true;
    if (map[cur.first][cur.second] == 3) {
      isPossible = true;
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
      if (map[nx][ny] != 1 && isVisited[nx][ny] == false) {
        q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  freopen("input1226.txt", "r", stdin);
  int t;
  for (t = 1; t <= 10; ++t) {
    isPossible = false;
    int Test_Case;
    cin >> Test_Case;

    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 16; ++j) {
        scanf("%1d", &map[i][j]);
        if (map[i][j] == 2) {
          start.first = i;
          start.second = j;
        }
        isVisited[i][j] = false;
      }
    }

    // dfs(start.first, start.second);
    bfs();

    cout << "#" << Test_Case << " " << isPossible << '\n';
  }
  return 0;
}