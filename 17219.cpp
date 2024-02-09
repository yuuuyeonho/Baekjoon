#include<iostream>
#include<map>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string site, psw;
    int n, m;
    cin >> n >> m;
    map<string,string> map;
    for(int i=0; i<n; ++i){
        cin >> site >> psw;
        map.insert(make_pair(site,psw));
    }
    for(int i=0; i<m; ++i){
        string tmp;
        cin >> tmp;
        cout << map[tmp] << endl;
    }
    return 0;
}   