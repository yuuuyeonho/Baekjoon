#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  freopen("levelup.txt", "r", stdin);
  int t;
  int Test_Case;
  cin >> t;
  for (Test_Case = 1; Test_Case <= t; ++Test_Case) {
    int n;
    cin >> n;
    int* point = new int[n];
    int* dist = new int[n];
    int totalDist = 0;

    for (int i = 0; i < n; ++i) {
      cin >> point[i];
    }

    for (int i = 1; i < n; ++i) {
      dist[i] = abs(point[i] - point[i - 1]);
      totalDist += dist[i];
    }

    int maxdiff = 0;

    for (int i = 2; i < n; ++i) {
      int diff = dist[i] + dist[i - 1] - abs(point[i] - point[i - 2]);
      if (diff > maxdiff) maxdiff = diff;
    }

    totalDist -= maxdiff;

    cout << totalDist << '\n';

    delete[] point;
    delete[] dist;
    cout.flush();
  }

  return 0;
}