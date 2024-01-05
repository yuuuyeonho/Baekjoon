#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int T, R;
    string S;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> R;
        cin >> S;
        int len = S.length();
        for(int j=0; j<len; ++j){
            for(int k=0; k<R; ++k){
                cout << S[j];
            }
        }
        cout << '\n';
    }
}