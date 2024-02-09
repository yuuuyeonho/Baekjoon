#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    short arr[10000] = {0,};

    int sum = 0;

    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    for(int i=0; i<n; ++i){
        while(arr[i]>0){
            if(arr[i]<=arr[i+1]){
                if(arr[i+1]<=arr[i+2]){       
                    arr[i]--;
                    arr[i+1]--;
                    arr[i+2]--;
                    sum+=7;

                }
                else{
                    arr[i]--;
                    arr[i+1]--;
                    sum+=5;
                }
            }
            else{
                    arr[i]--;
                    sum+=3;
                }
        }
    }

    cout << sum;
}