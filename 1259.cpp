#include<iostream>
#include<string>
using namespace std;

int main(){
    int len, halflen, n=1;
    string str;
    bool flag = true;
    while(true){
        cin >> n;
        if(n==0) break;
        str = to_string(n);
        len = str.length();
        halflen = len/2;
        for(int i=0; i<=halflen; ++i){
            if(str[i] != str[len-i-1]){
                flag = false;
                break;
            }
        }
        if(flag == true) cout << "yes" << endl;
        else cout << "no" << endl;
        flag = true;
    }
    return 0;
}