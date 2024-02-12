#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000003];
long long n, b, c;
long long sum = 0;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> b >> c;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    // solve
    // select b is better choice
    if(b < c){
        for(int i = 1; i <= n; i++)
            sum+= arr[i];
        cout << sum*b << '\n';
        return 0;
    }

    for(int i = 1; i <= n; i++){
        // 3개 불가능
        if(arr[i+1] > arr[i+2]){
            long long count = min(arr[i], arr[i+1] - arr[i+2]);
            sum += (b+c)*count;

            arr[i] -= count;
            arr[i+1] -= count;

            long long count2 = min(arr[i], min(arr[i+1], arr[i+2]));
            sum += (b+2*c)*count2;

            arr[i] -= count2;
            arr[i+1] -= count2;
            arr[i+2] -= count2;
        } 
        else{ 
            // 3개 가능
            long long count = min(arr[i], min(arr[i+1], arr[i+2]));
            sum += (b+2*c)*count;

            arr[i] -= count;
            arr[i+1] -= count;
            arr[i+2] -= count;

            long long count2 = min(arr[i], arr[i+1]);
            sum += (b+c)*count2;

            arr[i] -= count2;
            arr[i+1] -= count2;
        }
        sum += b*arr[i];
        arr[i] = 0;
    }

    cout << sum << '\n';
}

/*
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    long long n;
    long long b,c;
    cin >> n >> b >> c;
    long long arr[1000002] = {0,};

    long long sum = 0;
    long long count = 0, count2 = 0;

    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    if(b<c){
        for(int i=0; i<n; ++i){
            sum += arr[i];
        }
        cout << sum*b;
        return 0;
    }

    for(int i=0; i<n; ++i){ 
        if(arr[i+1]>arr[i+2]){
            count = min(arr[i],arr[i+1]-arr[i+2]);
            arr[i] -= count;
            arr[i+1] -= count;
            sum += (b+c)*count;

            count2 = min(arr[i], min(arr[i+1], arr[i+2]));
            arr[i] -= count2;
            arr[i+1] -= count2;
            arr[i+2] -= count2;
            sum += (b+2*c)*count2;
        }
        else{       //앞이 더 클 경우 앞에끼리 먼저 사는게 이득, 가격표에 따라 달라 질 수도.
            count = min(arr[i], min(arr[i+1], arr[i+2]));
            sum += (b+2*c)*count;

            arr[i] -= count;
            arr[i+1] -= count;
            arr[i+2] -= count;

            count2 = min(arr[i], arr[i+1]);
            sum += (b+c)*count2;

            arr[i] -= count2;
            arr[i+1] -= count2;
        }
        sum += b*arr[i];
        arr[i] = 0;
    }

    cout << sum;

    return 0;
}
*/