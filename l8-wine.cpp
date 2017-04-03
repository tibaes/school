#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n && n > 0) {
    long long work = 0;
    long long acc = 0;
    for (auto i = 0; i < n; ++i) {
      int a;
      cin >> a;
      acc += a;
      work += abs(acc);
    }
    cout << work << endl;
  }
  return 0;
}
