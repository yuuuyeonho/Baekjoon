#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt=0;
    while((N%5 != 0)&&(N>0)){
        N -= 3;
        cnt++;
    }
    if(N<0){
        cout << -1 << endl;
    }
    else{
        cnt += N/5;
        cout << cnt << endl;
    }
    return 0;
}