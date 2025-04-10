#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec[1001];
bool visited[1001];

void dfs(int n){
    visited[n] = true;
    for(int i=0; i<vec[n].size(); i++){
        int next = vec[n][i];
        if(visited[next] == false){
            dfs(next);
        }
    }
}

int main(){
    int n, m;
    int u, v;

    int cnt = 0;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        if(visited[i] == false){
            cnt++;
            dfs(i);
        }
    }

    cout << cnt;
}