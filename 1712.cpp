#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if(B>=C){
        cout << -1;
        return 0;
    }
    int BEP = A/(C-B);
    cout << BEP+1;
}