#include<iostream>
using namespace std;

int main(){
    int A, B, V;

    cin >> A >> B >> V;
    int day;
    int tmp = (V-A) / (A-B);
    if(((V-A) % (A-B))==0) day = tmp + 1;
    else day = tmp + 2;

    cout << day << endl;;

    return 0;
}