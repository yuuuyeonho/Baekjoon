#include <iostream>
using namespace std;

int ladder[101][101];
int dx[] = {-1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input1210.txt", "r", stdin);
  for (int t = 1; t <= 10; ++t) {
    int Test_Case;
    cin >> Test_Case;

    int x, y;

    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        cin >> ladder[i][j];
      }
    }

    // 도착지점부터 거슬러 올라가기 위해 초기 x,y값 설정
    for (int i = 0; i < 100; i++) {
      if (ladder[99][i] == 2) {
        x = i;
        break;
      }
    }
    y = 100;

    while (y != 0) {
      for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        if (nx < 0 || nx >= 100) continue;
        if (ladder[y][nx] == 1) {
          while (nx >= 0 && nx < 100 && ladder[y][nx] == 1) nx = nx + dx[i];
          x = nx - dx[i];
          break;
        }
      }
      y--;
    }

    cout << "#" << Test_Case << " " << x << '\n';
  }
  return 0;
}