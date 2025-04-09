#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

queue<pair<int,int> > q;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int map[1001][1001];

bool isInArea(int n, int m, int x, int y){
    if(x<0 || n<=x || y<0 || m<=y) return false;
    return true;
}

void bfs(int n, int m){
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isInArea(n,m,nx,ny) && map[nx][ny] == 1){
                q.push(make_pair(nx,ny));
                map[nx][ny] = map[x][y] + 1; 
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) q.push(make_pair(i,j));
        }
    }

    bfs(n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] >= 2) map[i][j] -= 2;
            else if(map[i][j] == 1) map[i][j] = -1;
            cout << map[i][j] << ' '; 
        }
        cout << "\n";    
    }

    return 0;
}