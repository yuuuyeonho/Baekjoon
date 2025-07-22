#include <iostream>
using namespace std;

int main() {
  int t;
  for (t = 0; t < 3; t++) {
    int n;
    cin >> n;
    long long sum = 0;
    long long flow = 0;
    long long tmp;
    long long prev;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      prev = sum;
      sum += tmp;
      if (tmp > 0 && prev > 0 && sum < 0) flow++;
      if (tmp < 0 && prev < 0 && sum > 0) flow--;
    }
    if (flow == 0) {
      if (sum == 0)
        cout << '0' << endl;
      else
        cout << (sum > 0 ? '+' : '-') << endl;
    } else {
      cout << (flow > 0 ? '+' : '-') << endl;
    }
  }
  return 0;
}