#include<iostream>
#include<queue>
using namespace std;

bool visited[200001];

int bfs(int n, int k){
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int distance[200000] = {0,};

    while(!q.empty()){
        int x = q.front();
        q.pop();
        // X+1로 가는 경우 
        if((x+1) <= k && !visited[x+1]){
            distance[x+1] = distance[x] + 1;
            if((x+1) == k){
                return distance[x+1];
            }
            visited[x+1] = true;
            q.push(x+1);
        }
        // X-1로 가는 경우
        if((x-1) >= 0 && !visited[x-1]){
            distance[x-1] = distance[x] + 1;
            if((x-1) == k){
                return distance[x-1];
            }
            visited[x-1] = true;
            q.push(x-1);
        } 
        // X*2로 순간이동 하는 경우
        if(x*2 <= 200000 && !visited[x*2]){
            distance[x*2] = distance[x] + 1;
            if((x*2) == k){
                return distance[x*2];
            }
            visited[x*2] = true;
            q.push(x*2);
        }
    }
    return 0;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << bfs(N,K);
}