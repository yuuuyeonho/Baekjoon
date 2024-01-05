#include<iostream>
#include<string>
using namespace std;

// 다 받아서 한번에 나오는 코드
int main(){
    int T;
    int sum=0;
    string str;
    cin >> T;
    string* answ = new string[T];
    for(int i=0; i<T; ++i){
        cin >> str;
        int len = str.length();
        for(int j=0; j<len; ++j){
            if(str[j] == '(') sum++;
            else if(str[j] == ')') sum--;
            if(sum < 0) break;
        }
        if(sum==0) answ[i] = "YES";
        else answ[i] = "NO";
        sum = 0;
    }
    for(int i=0; i<T; ++i){
        cout << answ[i] << endl;
    }
    delete[] answ;
    return 0;
}


/* 
한번 입력할 때 바로바로 나오는 코드

int main(){
    int T;
    int sum=0;
    string str;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> str;
        int len = str.length();
        for(int j=0; j<len; ++j){
            if(str[j] == '(') sum++;
            else if(str[j] == ')') sum--;
            if(sum < 0) break;
        }
        if(sum==0) cout << "YES" << endl;
        else cout << "NO" << endl;
        sum = 0;
    }
    return 0;
}
*/