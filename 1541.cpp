#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int l = str.length();
    int tmp=0, sum=0;
    bool isMinus = false;
    for(int i=0; i<l+1; ++i){
        if(str[i] == '+' || str[i] == '-' || i == l) {
            if(!isMinus) {
                sum += tmp;
                tmp = 0;   
            }
            else{
                sum -= tmp;
                tmp = 0;
            }
            if(str[i] == '-') isMinus = true;
        }
        else{
            tmp = 10*tmp + (str[i] - '0');
        }
    }

    cout << sum << endl;
}