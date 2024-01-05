#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    int* arr = new int[T];
    for(int i=0; i<T; ++i){
        cin >> arr[i];
    }
    int max = *max_element(arr,arr+T);
    int* cnt0 = new int[max+1];
    int* cnt1 = new int[max+1];
    cnt0[0] = 1;
    cnt0[1] = 0;
    cnt1[0] = 0;
    cnt1[1] = 1;
    int i = 2;
    while(i<=max){
        cnt0[i] = cnt0[i-1] + cnt0[i-2];
        cnt1[i] = cnt1[i-1] + cnt1[i-2];
        i++;
    } 
    for(i = 0; i<T; ++i){
        int index = arr[i];
        cout << cnt0[index] << ' ' << cnt1[index] << endl;
    }

    delete[] arr;
    delete[] cnt0;
    delete[] cnt1;

    return 0;
}