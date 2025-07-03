#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,
               greater<pair<int, pair<int, int> > > >
    pq;
int map[101][101] = {0};
int dist[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int INF = 12345678;

int main() {
  int t;
  cin >> t;
  for (int Test_Case = 1; Test_Case <= t; Test_Case++) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%1d", &map[i][j]);  // map에 파여진 깊이 받기
        dist[i][j] = INF;          // 초기 dist 무한대 설정
      }
    }

    dist[0][0] = 0;
    pq.push(make_pair(0, make_pair(0, 0)));

    while (!pq.empty()) {
      int cost = pq.top().first;
      pair<int, int> cur = pq.top().second;
      pq.pop();

      for (int i = 0; i < 4; i++) {
        pair<int, int> next = make_pair(cur.first + dx[i], cur.second + dy[i]);
        int nx = next.first;
        int ny = next.second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        int ncost = cost + map[nx][ny];
        if (ncost < dist[nx][ny]) {
          dist[nx][ny] = ncost;
          pq.push(make_pair(ncost, next));
        }
      }
    }
    cout << "#" << Test_Case << " " << dist[n - 1][n - 1] << endl;
  }
  return 0;
}