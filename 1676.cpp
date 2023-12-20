#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;

    int hwf = N/125;
    int tw = N/25 - hwf;
    int fv = N/5 - hwf - tw;
    
    int zero = fv + 2*tw + 3*hwf;
    
    cout << zero << endl;
}