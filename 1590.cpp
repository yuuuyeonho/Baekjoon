#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, T;
    cin >> N >> T;
    int S, I, C;
    vector<long long> timetable;
    for(int i=0; i<N; ++i){
        cin >> S >> I >> C;
        for(int j=0; j<C; ++j){
            long long t = S+I*j;
            timetable.push_back(t);
        }
    }
    sort(timetable.begin(),timetable.end());

    int l = 0;
    int h = timetable.size();
    int m;
    while(l<h){
        m = (l+h)/2;
        if(T > timetable.at(m)) l = m+1;
        else h = m;
    }
    if(timetable[l] - T < 0) cout << -1;
    else cout << timetable.at(l) - T;
    return 0;
}