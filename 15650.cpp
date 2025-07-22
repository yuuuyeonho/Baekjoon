#include <iostream>
using namespace std;

#define MAX 9

int n, m;
int arr[MAX];

void dfs(int num, int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  } else {
    for (int i = num; i <= n; ++i) {
      arr[cnt] = i;
      dfs(i + 1, cnt + 1);
    }
  }
}

int main() {
  cin >> n >> m;
  dfs(1, 0);

  return 0;
}