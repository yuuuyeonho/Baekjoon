#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  int min1 = min(x, y);
  int min2 = min(w - x, h - y);
  int min0 = min(min1, min2);
  cout << min0;
}