#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    char str[n];
    cin >> str;
    int ascii, sum=0;
    for(int i=0; i<n; ++i){
        ascii = str[i] - 96;
        sum += ascii * pow(31,i);
    }
    int hash = sum%1234567891;
    cout << hash << endl;
}