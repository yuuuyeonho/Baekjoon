#include<iostream>
using namespace std;

void visit(n){
    if(row ==r && column == c) {cout << cnt; return;}
    else if((row<=r && r<=row*pow(2,n-1)) && (column<=c && c<=column*pow(2,n-1))){
        visit(n/2);
    }
    else if((row+pow(2,n-1)<=r && r<=row*pow(2,n)) && (column<=c && c<=column*pow(2,n-1))){
        
    }
}

int main(){
    int n, r, c;
    cin >> n >> r >> c;
    int row =0
    int column = 0
    int cnt = 0;

    
}