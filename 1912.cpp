#include<iostream>
using namespace std;

int main(){
    int i;
    int n;
    cin >> n;

    int arr[n];
    for(i=0; i<n; ++i){
        cin >> arr[i];
    }

    int sum[n];
    int max[n];

    int tmp;
    int tmp_max=-1000;
    for(int k=0; i<n; ++k){
        for(i=k; i<n; ++i){
            for(int j=i; j<n; ++j){
                tmp += arr[j];
            }
            sum[i] = tmp;
        }

        for(i=k; i<n; ++i){
            if(sum[i] > tmp_max) tmp_max = sum[i];
        } 
        max[k] = tmp_max;
    }


    int total_max = max[0]; 
    for(i=1; i<n; ++i){
        if(max[i] > total_max) total_max = max[i];
    }

    cout << total_max;
    return 0;
}