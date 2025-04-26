#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

queue<pair<long long, long long> > q;
int dist[100000000] = {0};

int bfs(long long a, long long b){
    q.push(make_pair(a,1));
    while(!q.empty()){
        pair<long long, long long> cur = q.front();
        q.pop();
        if(cur.first == b) return cur.second;
        if(2*cur.first <= b){
            q.push(make_pair(2*cur.first, cur.second+1));
            //cout << 2*cur << " dist = " << dist[2*cur] << "\n"; 
        }
        if((10*cur.first)+1<=b) {
            q.push(make_pair((10*cur.first)+1, cur.second+1)); 
            //cout << 10*cur+1 << " dist = " << dist[10*cur+1] << "\n";
        }
    }
    return -1;
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long result = bfs(a, b);

    cout << result;

    return 0;
}