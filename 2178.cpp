#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int cnt = 0;
int N, M;
int state[101][101];
int arr[101][101];
int dist[101][101]; 

int x_m[4] = {-1, 1, 0, 0};
int y_m[4] = {0, 0, -1, 1};

queue<pair<int,int> > q;

void bfs(int xpos, int ypos){
    state[xpos][ypos] = 1;
    q.push(make_pair(xpos,ypos));
    dist[xpos][ypos]++;

    while(!q.empty()){
        cnt++;
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; ++i){
            int x_new = x + x_m[i];
            int y_new = y + y_m[i];


            if ( (0 <= x_new && x_new < N) && (0 <= y_new && y_new < M) 
            && !state[x_new][y_new] && arr[x_new][y_new] == 1 ){
				dist[x_new][y_new] = dist[x][y] + 1;
				q.push(make_pair(x_new, y_new));
				state[x_new][y_new] = 1;    
            }
        }
    }
}


int main(){
    cin >> N >> M;

    /*
    string tmp;
    getline(cin, tmp, '\n');
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            arr[i][j] = cin.get();
        }
    }
    */
    for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			arr[i][j] = str[j] - '0';
		}
	}

    bfs(0,0);
    
    cout << dist[N-1][M-1];
}
