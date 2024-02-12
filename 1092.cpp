#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> crain;
vector<int> box;

void carry(){
    int flag = false;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<box.size(); ++j) {
            if(crain[i] >= box[j]) {
                box.erase(box.begin()+j);
                break;
            }
        }
    }
}

int main() {
    int tmp;

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> tmp;
        crain.push_back(tmp);
    }

    cin >> M;
    for(int i=0; i<M; ++i) {
        cin >> tmp;
        box.push_back(tmp);
    }

    sort(crain.begin(), crain.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if(crain[0] < box[0]) {
        cout << -1;
        return 0;
    }

    int time = 0;

    while(box.size() > 0) {
        time++;
        carry();
    }
    
    cout << time;

    return 0;
}