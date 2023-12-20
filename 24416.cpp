#include<iostream>
using namespace std;

int cnt1=0, cnt2=0;

int fib(int n){
        if(n==1 || n==2){
            cnt1++;
            return 1;
        }
        else{
            return (fib(n-1) + fib(n-2));
        }
    }

int fibonacci(int n,int f[]){
    if(n==1 || n==2){
        cnt2++;
    }
    for(int i=3; i<(n+1); ++i){
        f[i] = f[i-1] + f[i-2];
        cnt2++;
    }
    return f[n];
}

int main(){
    int n;
    cin >> n;
    
    int *f = new int[n+1];
    f[1] = 1;
    f[2] = 1;
    
    fib(n);
    fibonacci(n,f);

    
    cout << cnt1 << ' ' << cnt2;
    delete[] f;
}