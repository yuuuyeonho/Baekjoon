#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string tmp;

    int n;
    cin >> n;
    cin >> str;
    for(int i=0; i<n-1; ++i){
        cin >> tmp;
        for(int j=0; j<str.length(); ++j){
            if(str[j]!=tmp[j]) str[j] = '?';
        }
    }
    cout << str;

    return 0;
}