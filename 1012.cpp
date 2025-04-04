#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int graph[50][50];

void bfs(int x, int y, int m, int n){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    graph[x][y] = 0;
    //cout << "(" << x << "," << y << ")" << " = 0\n";

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        
        int nx = current.first;
        int ny = current.second;

        for(int i=0; i<4; i++){
            int qx = nx + dx[i];
            int qy = ny + dy[i];

            if(qx<0 || m<=qx || qy<0 || n<= qy) continue;

            if(graph[qx][qy] == 1){
                q.push(make_pair(qx,qy));
                graph[qx][qy] = 0;
                //cout << "(" << qx << "," << qy << ")" << " = 0\n";
            }
        }
    }

    //cout << endl << endl;
}

int main() {
    int T; 
    cin >> T;

    for(int i=0; i<T; i++){
        int M, N, K;
        int x, y;
        int cnt=0;
        cin >> M >> N >> K;

        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                graph[j][k] = 0;
            }
        }

        for(int j=0; j<K; j++){
            cin >> x >> y;
            graph[x][y] = 1;
        }

    //     for (int j = 0; j < M; j++)    // 2차원 배열의 세로 크기만큼 반복
    // {
    //     for (int k = 0; k < N; k++)    // 2차원 배열의 가로 크기만큼 반복
    //     {
    //         printf("%d ", graph[j][k]); // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
    //     }
    //     printf("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
    // }

        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                if(graph[j][k] == 1) {
                    bfs(j, k, M, N);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
}