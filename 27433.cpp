#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long result=1;
    for(int i=n; i>0; --i){
        result *= i;
    }
    cout << result;

    return 0;
}