#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int arr[1000];
    int i, j=1, cnt=1;
    int sum=0;
    for(i = 0; i < 1000; ++i){
        arr[i] = j;
        cnt++;
        if(cnt > j){
            j++;
            cnt = 1;
        }
    }
    for(i = a-1; i < b; ++i){
        sum = sum + arr[i];
    }
    cout << sum;
}