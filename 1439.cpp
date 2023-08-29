#include<iostream>
#include<string>
using namespace std;

int do_zero(string s, int l){
    int cnt=0;
    bool flag = true;
    for(int i=0; i<l; ++i){
        if(s[i] == '1' && flag == true){
            cnt++;
            flag = false;
        }
        else if(s[i] == '0' && flag == false){
            flag = true;
        }
    }
    return cnt;
}

int do_one(string s, int l){
    int cnt=0;
    bool flag = true;
    for(int i=0; i<l; ++i){
        if(s[i] == '0' && flag == true){
            cnt++;
            flag = false;
        }
        else if(s[i] == '1' && flag == false){
            flag = true;
        }
    }
    return cnt;
}

int main(){
    string s;
    cin >> s;
    int result;
    int l = s.length();
    
    if(s[0] == '0') result = do_zero(s,l);
    else if(s[0] == '1') result = do_one(s, l);

    cout << result << endl;
}

