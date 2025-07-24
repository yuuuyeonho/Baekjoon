#include <iostream>
using namespace std;

#define MAX 21

int visit[26];  // 지나간 알파벳인지 확인
char board[MAX][MAX];
int max_cnt;
int R, C;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void init() {
  for (int i = 0; i <= 26; ++i) {
    visit[i] = 0;
  }
  max_cnt = 0;
}

void input() {
  cin >> R >> C;
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cin >> board[i][j];
    }
  }
}

void dfs(int x, int y, int cnt) {
  char curCh = board[x][y];

  if (cnt == R * C) {
    max_cnt = cnt;
    return;
  }

  visit[curCh - 'A'] = 1;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
    char nCh = board[nx][ny];
    if (visit[nCh - 'A'] == 1) {
      if (max_cnt < cnt) max_cnt = cnt;
      continue;
    }
    dfs(nx, ny, cnt + 1);
  }
  visit[curCh - 'A'] = 0;

  return;
}

int main() {
  init();
  input();
  dfs(1, 1, 1);

  cout << max_cnt;

  return 0;
}