#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    int alp[26] = {0};
    int tmp;
    cin >> str;
    int l = str.length();
    for(int i=0; i<l; ++i){
        tmp = str[i] - 'a';
        alp[tmp]++;
    }
    for(int i=0; i<26; ++i) cout << alp[i] << ' ';
    
}