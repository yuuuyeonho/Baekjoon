#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int cnt=0;
    int l = str.length();
    for(int i=0; i<l; ++i,++cnt){
        if(cnt == 10){cout << endl; cnt = 0;}
        cout << str[i];
    }
    return 0;
}