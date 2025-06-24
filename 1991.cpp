#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> alp[26];

void preorder(int cur) {
  if (cur == -1) return;
  char ch = 'A' + cur;
  cout << ch;
  preorder(alp[cur].first);
  preorder(alp[cur].second);
}

void inorder(int cur) {
  if (cur == -1) return;
  inorder(alp[cur].first);
  char ch = 'A' + cur;
  cout << ch;
  inorder(alp[cur].second);
}

void postorder(int cur) {
  if (cur == -1) return;
  postorder(alp[cur].first);
  postorder(alp[cur].second);
  char ch = 'A' + cur;
  cout << ch;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  char x, y, z;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (y == '.')
      alp[x - 'A'].first = -1;
    else
      alp[x - 'A'].first = y - 'A';

    if (z == '.')
      alp[x - 'A'].second = -1;
    else
      alp[x - 'A'].second = z - 'A';
  }

  preorder(0);
  cout << '\n';
  inorder(0);
  cout << '\n';
  postorder(0);

  return 0;
}