#include<iostream>
#include<algorithm>
using namespace std;

bool second_sorting(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}


int main(){
    int N;
    int tmp;
    cin >> N;
    pair<int, int> p[N];
    for(int i=0; i<N; ++i){
        cin >> tmp;
        p[i].first = tmp;
        p[i].second = i;
    }
    sort(p,p+N);
    int step=0;
    tmp = p[0].first;
    for(int i=0; i<N; ++i){
        if(p[i].first != tmp) {
            step++;
            tmp = p[i].first;
        }
        p[i].first = step;
    }
    sort(p,p+N,second_sorting);

    for(int i=0; i<N; ++i){
        cout << p[i].first << " ";
    }

    return 0;
}