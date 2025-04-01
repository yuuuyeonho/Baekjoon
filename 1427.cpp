#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(int i, int j){
    return j < i;
}

int main(){
    string str;

    cin >> str;

    // int *num = new int[str.length()];

    // for(int i=0; i<str.length(); ++i){
    //     num[i] = str[i] - '0';
    // }

    char *num = new char[str.length()];

    for(int i=0; i<str.length(); ++i){
        num[i] = str[i];
    }

    sort(num,num+str.length(), compare);

    cout << num;
}   