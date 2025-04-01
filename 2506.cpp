#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp, sum = 0;
    int score = 1;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        if(tmp == 1) {
            sum += score;
            score++;
        }
        else {
            score = 1;
        }
    }
    
    cout << sum;
    
    return 0;
}