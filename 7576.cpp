#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

queue<pair<int,int> > q;
vector<pair<int,int> > v;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
    int m, n;
    cin >> n >> m;

    int box[m][n];
    int day = 0;
    int notyet = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) q.push(make_pair(i,j));
            else if(box[i][j] == 0) notyet++;
        }
    }

    if(notyet == 0){
        cout << 0;
        return 0;
    }
    
    while(!q.empty()){
        for(int i=0; i<q.size(); i++){
            pair<int,int> cur = q.front();
            q.pop();

            int nx = cur.first;
            int ny = cur.second;
            
            for(int j=0; j<4; j++){
                int qx = nx + dx[j];
                int qy = ny + dy[j];

                if(qx<0 || m<=qx || qy<0 || n<=qy) continue;
                if(box[qx][qy] == 0){
                    q.push(make_pair(qx,qy));
                    //토마토 익히기
                    box[qx][qy] = box[nx][ny]+1;
                }
            }
        }
    }

    // for (int j = 0; j < m; j++){    // 2차원 배열의 세로 크기만큼 반복
    //     for (int k = 0; k < n; k++){    // 2차원 배열의 가로 크기만큼 반복
    //         printf("%d ", box[j][k]); // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
    //     }
    //     printf("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
    // }
    // printf("\n");

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(box[i][j] == 0){
                cout << "-1";
                return 0;
            }
            if(day < box[i][j]){
                day = box[i][j];
            }
        }
    }

    cout << day-1;
    return 0;
}