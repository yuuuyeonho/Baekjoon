#include<iostream>
#include<cmath>
using namespace std;

int cnt = 0;

void cal(int n, int r, int c) {
    int nr = 0;
    int nc = 0;
    int block = pow(2,(n-1));
    // cout << "n = " << n << " r = " << r << " c = " << c << " block = " << block << endl;
    if(r >= block) nr = 1;
    if(c >= block) nc = 1;
    if(nr == 1 && nc == 1) {
        int tmp = block*block * 3;
        cnt += tmp;
        // cout << "case1 and cnt + " << tmp << endl;
        r = r - block;
        c = c - block;
    }
    else if(nr==1 && nc == 0) {
        int tmp = block*block * 2;
        cnt += tmp;
        // cout << "case2 and cnt + " << tmp << endl;
        r = r - block;
    }
    else if(nr==0 && nc == 1) {
        int tmp = block*block;
        cnt += tmp;
        // cout << "case3 and cnt + " << tmp << endl;
        c = c - block;
    }
    else;

    if(n == 1) return;
    cal(n-1, r, c);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    cal(N,r,c);

    cout << cnt;
}