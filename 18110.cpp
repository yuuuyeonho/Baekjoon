#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    if(n==0){
        cout << 0;
        return 0;
    }
    double tmp = n;
    sort(arr,arr+n);
    int exc = floor((tmp*0.15+0.5));
    int high = n-exc;
    double sum = 0;
    for(int i=exc; i<high; ++i){
        sum += arr[i];
    }
    int avg = floor((sum/(n-2*exc))+0.5);
    cout << avg << endl;
    delete[] arr;
    return 0;
}

/*
    <cmath> 헤더로 ceil, floor함수 사용 가능
    floor 내림함수를 이용해서 반올림 구현하기
    floor(n+0.5)를 하면 n의 반올림이 된다.
*/