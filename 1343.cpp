#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int l = str.length();

    int flag, cnt=0;

    for(int i=0; i<l+1; ++i){
        if(str[i] == 'X') cnt++;
        else if(((str[i] == '.' || i == l) && cnt>0)){
            if(cnt%2 != 0){
                cout << "-1" << endl;
                return 0;
            }
            else{
                if(cnt %4 == 0){
                    for(int j=i-cnt; j<i; ++j) str[j] = 'A'; 
                }
                else{
                    for(int j=i-cnt; j<i-2; ++j) str[j] = 'A';
                    str[i-2] = 'B';
                    str[i-1] = 'B';
                }
                cnt = 0;
            }
        }
    }

    cout << str << endl;
}