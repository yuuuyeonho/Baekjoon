#include<iostream>
#include<set>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    bool S[21] = {false};

    int m;
    cin >> m;

    string command;
    int x;
    for(int i=0; i<m; ++i){
        cin >> command;
        if(command == "all"){
            for(int j=1; j<=20; ++j){
                S[j] = true;
            }
            continue;
        }
        else if(command == "empty"){
            for(int j=1; j<=20; ++j){
                S[j] = false;
            }
            continue;
        }
        else{
            cin >> x;
            if(command == "add") {
                S[x] = true;
            }
            else if(command == "remove") {S[x] = false;}
            else if(command == "check"){
                if(S[x]==true) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            else if(command == "toggle"){
                if(S[x]==true) S[x] = false;
                else S[x] = true;
            }
        }
    }

    return 0;
}