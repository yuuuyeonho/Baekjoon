#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    short arr[10002] = {0,};

    int sum = 0;

    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    for(int i=0; i<n; ++i){
        while(arr[i]>0){    //각 공장을 다 털 때까지
            if(arr[i]<=arr[i+1]){   //arr[i+1]이 arr[i] 보다 크면 arr[i+1]>1 보장, 
                if(arr[i+1]<=arr[i+2]){     //이 경우 세개를 한번에 사는게 이득,  
                    arr[i]--;
                    arr[i+1]--;
                    arr[i+2]--;
                    sum+=7;

                }
                else{       //앞이 더 클 경우 앞에끼리 먼저 사는게 이득, 가격표에 따라 달라 질 수도.
                    arr[i]--;
                    arr[i+1]--;
                    sum+=5;
                }
            }
            else{       //앞이 더 클 경우 앞에끼리 먼저 사는게 이득, 가격표에 따라 달라 질 수도.
                    arr[i]--;
                    sum+=3;
                }
        }
    }

    cout << sum;
}