#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int bd = b * d;
    int cd = c * d;
    int ea = e * a;
    int fa = f * a;

    int ae = a * e;
    int ce = c * e;
    int db = d * b;
    int fb = f * b;

    int x = (ce - fb) / (ae - db);
    int y = (cd - fa) / (bd - ea);

    cout << x << ' ' << y;

    return 0;
}