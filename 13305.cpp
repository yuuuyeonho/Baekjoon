#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long distance[n-1];
    long long oilprice[n];
    int i, flag;
    for(int i=0; i<n-1; ++i) cin >> distance[i];
    for(int i=0; i<n; ++i) cin >> oilprice[i];

    long long sum = 0;

    for(i=0, flag=i+1; flag<n; i=flag,++flag){
        sum += oilprice[i] * distance[flag-1];
        if((oilprice[flag] >= oilprice[i]) || flag == n-1) continue;
        else break;
    }


    cout << sum;
}

/*
다음 도시를 다룰 때마다 flag를 꽂는다.
(현재 도시의 기름가격) * (이전 도시-flag도시의 거리)를 곱해서 sum에 더한다.
flag 도시의 기름 가격이 현재 도시보다 비싸다면 i는 현재 도시로 계속 진행
flag 도시의 기름 가격이 현재 도시보다 싸다면 i = flag로 바꿔서 진행했다.
*/