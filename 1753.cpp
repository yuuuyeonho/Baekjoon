#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 12345678

vector<pair<int, int> > vec[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq;
int dist[20005];

int main() {
  int V, E;
  int K;

  cin >> V >> E;
  cin >> K;
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    vec[u].push_back(make_pair(v, w));
  }

  for (int i = 1; i <= V; i++) dist[i] = INF;

  dist[K] = 0;

  pq.push(make_pair(0, K));

  while (!pq.empty()) {
    int cost = pq.top().first;  // 현재 정점까지 거리
    int cur = pq.top().second;  // 현재 정점
    pq.pop();

    for (int i = 0; i < vec[cur].size(); i++) {
      int next = vec[cur][i].first;    // 다음 정점
      int ncost = vec[cur][i].second;  // 다음 정점까지의 거리

      if (cost + ncost < dist[next]) {
        dist[next] = cost + ncost;
        pq.push(make_pair(cost + ncost, next));
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << "\n";
  }

  return 0;
}