#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[100001];
int state[100001];
vector<int> node[100000];

void getparents(int n) {
    state[n] = 1;
    for(int i=0; i<node[n].size(); ++i) {
        int tmp = node[n].at(i);
        if(arr[node[n].at(i)]==0) {
            arr[node[n].at(i)] = n;
        }
        if(state[node[n].at(i)] == 0){
            getparents(tmp);
        }
    }
}

int main() {
    cin >> n;
    
    int tmp1, tmp2;
    for(int i=0; i<n-1; ++i) {
        cin >> tmp1 >> tmp2;
        node[tmp1].push_back(tmp2);
        node[tmp2].push_back(tmp1);
    }

    /*
    for(int i=1; i<=n; ++i){
        for(int j=0; j<node[i].size(); ++j){
            cout << node[i].at(j) << ' ';
        }
        cout << endl;
    } 
    */   

    getparents(1);

    for(int i=2; i<=n; ++i) {
        cout << arr[i] << endl;
    }

    return 0;
}