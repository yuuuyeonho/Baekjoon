#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num[n];
    int tmp, sum = 0;
    for(int i=0; i<n; ++i) cin >> num[i];

    sort(num, num+n);

    for(int i=0; i<n-1; ++i){
        tmp = num[i+1] - num[i];
        sum += tmp;
    }

    sum += num[n-1] - num[0];

    cout << sum << endl;
}