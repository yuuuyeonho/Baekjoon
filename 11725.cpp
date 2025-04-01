#include <iostream>
#include <vector>
using namespace std;

int n;
int parents[100001]; // 노드의 부모 번호
int state[100001]; // 이미 확인한 노드인지 구분
vector<int> node[100001]; // 각 노드에서 연결된 정점을 벡터 배열을 통해 표현

// parents 배열에 부모의 번호를 찾아서 넣는 함수 DFS로 구현
void getparents(int n) {
    state[n] = 1;
    for(int i=0; i<node[n].size(); ++i) {
        int child = node[n].at(i);
        if(parents[child]==0) {
            parents[child] = n;
        }
        if(state[child] == 0){
            getparents(child);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;
    
    int tmp1, tmp2;
    for(int i=0; i<n-1; ++i) {
        cin >> tmp1 >> tmp2;
        node[tmp1].push_back(tmp2);
        node[tmp2].push_back(tmp1);
    }

    getparents(1);

    for(int i=2; i<=n; ++i) {
        cout << parents[i] << '\n';
    }

    return 0;
}