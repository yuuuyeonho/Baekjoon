// 시간복잡도와 메모리 제한이 중요했던 문제. 10000  scanf, printf가 cin, cout보다 빠르다.
#include<stdio.h>

int main(){
    int n, i, j;
    short tmp;

    scanf("%d",&n);
    
    int arr[10001]={0,};
    
    for(i=0; i<n; ++i){
        scanf("%hd",&tmp);
        arr[tmp]++;
    }
    
    for(i=1; i<10001; ++i){
        if(arr[i]!=0){
            for(j=0; j<arr[i]; ++j) printf("%d\n",i);
        }
    }
}

/*
#include<iostream>

int main(){

    //cin, cout을 빠르게 돌릴 수 있는 입력문
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);


    int n, i, j;
    short tmp;

    cin >> n;
    
    int arr[10001]={0,};
    
    for(i=0; i<n; ++i){
        cin >> tmp;
        arr[tmp]++;
    }
    
    for(i=1; i<10001; ++i){
        if(arr[i]!=0){
            for(j=0; j<arr[i]; ++j) cout << i << '\n';
        }
    }
}
*/