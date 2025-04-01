#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;
    pair<int, int> p[n];

    for(int i=0; i<n; ++i){
        cin >> p[i].first >> p[i].second;
    }

    sort(p,p+n);

    for(int i=0; i<n; ++i){
        cout << p[i].first << ' ' << p[i].second << '\n';
    }
   
   return 0;
}