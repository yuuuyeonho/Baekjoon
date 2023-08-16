#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int tmp, cnt=1;
    tmp = n;
    do{
        tmp = (tmp%10)*10 + (tmp/10 + tmp%10)%10;
        if(tmp != n) cnt++;
    }while(tmp!=n);

    cout << cnt;
}