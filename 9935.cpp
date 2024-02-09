#include<iostream>
#include<string>
using namespace std;

bool cmp(char ch[], string str, int len, int index){
    int tmp = len-1;
    for(int i=0; i<len; ++i){
        if(ch[index--] != str[tmp--]) return false;
    }
    return true;
}   

int main(){
    string str;
    string bomb;
    cin >> str;
    cin >> bomb;

    /*
    int len = bomb.length();
    while(str.find(bomb) != string::npos){
        int tmp = str.find(bomb);
        str.erase(tmp,len);
    }

    if(str.length()==0) cout << "FRULA";
    else cout << str;
    */
    bool isit = true;
    int bomb_len = bomb.length(); //폭발어 길이
    char flag = bomb[bomb_len-1];
    int len = str.length(); // 전체문장 길이
    char stack[str.length()]; // 문장을 받을 스택
    int l = 0;
    for(int i=0; i<len; ++i, ++l){
        stack[l] = str[i]; // 스택에 한 글자씩 넣다가
        if(str[i] == flag){     // 폭발어 마지막 문자가 들어가면 그 앞 폭발어만큼 길이가 폭발어인지 비교
            if(cmp(stack, bomb, bomb_len, l)==true) l -= bomb_len; // 맞을시 스택 꺼내기(스택 마지막 당기기)
        }
    }


    if(l==0) cout << "FRULA" << endl;
    else{
        for(int i=0; i<l; ++i){
            cout << stack[i];
        }
    }
    return 0;
}