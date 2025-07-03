#include<iostream>
using namespace std;

const int NMAX = 1010101;



long long seg[NMAX*4];

long long upd(int node, int l, int r, int target, long long val) {
    if (target < l || target > r) return seg[node];
    if (target == l && target == r) return seg[node] = val; // +=
    int mid = (l + r) / 2;
    return seg[node] = (
        upd(node * 2, l, mid, target, val) +
        upd(node * 2 + 1, mid + 1, r, target, val)
        );
}
long long query(int node, int l, int r, int wl, int wr) {
    if (l > wr || r < wl) return 0; //항등원
    if (wl <= l && r <= wr) return seg[node];
    int mid = (l + r) / 2;
    return (
        query(node * 2, l, mid, wl, wr) +
        query(node * 2 + 1, mid + 1, r, wl, wr)
        );
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    if (int i=1; i<=n; i++){
        long long t; cin >> t;
        upd(1, 1, n, 1, t);
    }
    int q = n+k;
    while(q--){
        ll a, b, c,
        for(){}
    }
}