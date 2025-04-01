#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    pair<int, int> p[n];
    for(int i=0; i<n; ++i){
        cin >> p[i].second >> p[i].first;
    }
    sort(p,p+n);
    for(int i=0; i<n; ++i){
        cout << p[i].second << ' ' << p[i].first << '\n';
    }
    return 0;
}   