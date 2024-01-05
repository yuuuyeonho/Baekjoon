#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, i, cnt=0;
    cin >> N >> M;
    string tmpstr;
    string unheared[N];
    vector <string> unknown;
    for(i=0; i<N; ++i)
        cin >> unheared[i];
    sort(unheared,unheared+N);
    for(i=0; i<M; ++i){
        cin >> tmpstr;
        if(binary_search(unheared,unheared+N,tmpstr)){
            unknown.push_back(tmpstr); 
            cnt++;
            }
        else continue;
    }
    sort(unknown.begin(), unknown.end());
    cout << cnt << '\n';
    for(i=0; i<cnt; ++i){
        cout << unknown.at(i) << '\n';
    }
    return 0;
}