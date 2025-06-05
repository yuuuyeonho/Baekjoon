#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321;

vector<pair<int, int>> vec[1001];
queue<int> q;
int dist[1001];
bool isdistited[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second < b.second;
}

int main() {
  int n, m;
  int start, end;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int v, w, d;
    cin >> v >> w >> d;
    vec[v].push_back(make_pair(w, d));
  }

  cin >> start >> end;

  for (int i = 0; i < 1001; i++) {
    dist[i] = INF;
    isdistited[i] = false;
    sort(vec[i].begin(), vec[i].end(), compareBySecond);
  }

  dist[start] = 0;
  q.push(start);

  pq.push(make_pair(0, start));
  dist[start] = 0;  // 출발 도시 비용 = 0
  while (!pq.empty()) {
    int cost = pq.top().first;  // 현재 도시까지 비용
    int x = pq.top().second;    // 현재 도시
    pq.pop();

    // 현 도시까지 비용이 이미 기록된 비용보다 크면 pass
    if (dist[x] < cost) continue;

    // x 도시와 이어진 도시들 검사
    for (int i = 0; i < vec[x].size(); i++) {
      int nx = vec[x][i].first;             // 다음 도시
      int ncost = cost + vec[x][i].second;  // 다음 도시까지 비용

      // 기록되어진 비용보다 지금 비용이 더 작다면
      // 큐에 넣어줌
      if (dist[nx] > ncost) {
        pq.push(make_pair(ncost, nx));
        dist[nx] = ncost;  // 비용 다시 기록
      }
    }
  }

  //   while (!q.empty()) {
  //     int cur = q.front();
  //     q.pop();

  //     int d = dist[cur];

  //     for (int i = 0; i < vec[cur].size(); i++) {
  //       int to = vec[cur][i].first;
  //       int cost = vec[cur][i].second;
  //       q.push(to);
  //       if (d + cost < dist[to]) {
  //         dist[to] = d + cost;
  //       }
  //     }
  //   }

  cout << dist[end];

  return 0;
}