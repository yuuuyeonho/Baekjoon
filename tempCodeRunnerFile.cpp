#include<iostream>
using namespace std;

void cal(int arr[0], int N){
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for(int i=6; i<N+1; ++i)
        arr[i] = arr[i-1] + arr[i-5];
}

int main(){
    int T;
    cin >> T;

    int i;
    int* test = new int[T];
    
    for(i=0; i<T; ++i){
        cin >> test[i];
    }

    int N = 0;

    for(i=0; i<T; ++i){
        if(test[i] > N) N = test[i];
    }

    int* padoban = new int[N+1];

    cal(padoban,N);

    for(i=0; i<T; ++i){
        cout << padoban[test[i]] << endl;
    }


    delete[] test;
    delete[] padoban;
    return 0;
}