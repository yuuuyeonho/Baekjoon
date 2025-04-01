#include<iostream>
#include<string>
using namespace std;


int isGroup(string str){
    int l = str.length();
    if(l<=2) return 1;
    for(int i=1; i<l; ++i){
        if(str[i-1] != str[i]){
            char c = str[i-1];
            for(int j=i; j<l; ++j){
                if(c == str[j]) return 0;
            }
        }
    }
    return 1;
}


int main(){
    int n;
    cin >> n;
    string str;
    int count = 0;
    for(int i=0; i<n; ++i){
        cin >> str;
        if(isGroup(str))
            count++;
    }
    cout << count;
}