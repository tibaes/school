#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, m, c, k;
  cin >> t;
  while (t--) {
    cin >> m >> c;
    vector<vector<int>> v(m);
    while (c--) {
      cin >> k;
      v[k % m].push_back(k);
    }
    for (auto i = 0; i < m; ++i) {
      cout << i;
      for (const auto &vi : v[i])
        cout << " -> " << vi;
      cout << " -> \\" << endl;
    }
    if (t)
      cout << endl;
  }
  return 0;
}
