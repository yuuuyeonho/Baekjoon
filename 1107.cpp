#include<iostream>
using namespace std;

int main(){
    int N , tmp, i;
    cin >> N;
    int num[10] = {1,1,1,1,1,1,1,1,1,1};
    int M;
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> tmp;
        num[tmp]--;
    }
    
}