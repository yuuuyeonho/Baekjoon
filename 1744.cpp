#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int arr[N];
    int cnt=0;

    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    sort(arr,arr+N);

    int zero = -1; 
    int flag = -1;

    for(int i=0; i<N; ++i){
        if(arr[i] == 0){
            zero = i;
            break;
        }
        else if(arr[i] > 0){
            flag = i;
            break;
        }
    }

    if(zero >= 0){
        int i, j;
        int tmp1, tmp2;
        for(i=0, tmp1 = arr[i], tmp1 = arr[i+1]; tmp1 != 0, tmp2 != 0; i+=2, tmp1 = arr[i], tmp1 = arr[i+1]){
            cnt += tmp1 * tmp2;
        }
        if(tmp1 == 0){
            j = zero+1;
        }
        else{
            cnt += tmp1 * tmp2;
            j = zero+1;
        }
    }
}