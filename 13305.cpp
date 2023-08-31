#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int distance[n-1];
    int oilprice[n];
    int i, flag;
    for(int i=0; i<n-1; ++i) cin >> distance[i];
    for(int i=0; i<n; ++i) cin >> oilprice[i];

    int sum = 0;

    for(i=0, flag=i+1; flag<n; i=flag,++flag){
        sum += oilprice[i] * distance[flag-1];
        if((oilprice[flag] >= oilprice[i]) || flag == n-1) continue;
        else break;
    }


    cout << sum;
}