#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  while ((cin >> n >> d) && n && d) {
    vector<char> v;
    v.reserve(12345);

    auto rm = 0;
    for (auto got_n = 0; got_n < n; ++got_n) {
      char c;
      cin >> c;
      while (rm < d && !v.empty() && (v.back() < c)) {
        v.pop_back();
        rm++;
      }
      v.push_back(c);
    }

    for (uint i = 0; i < v.size() - (d - rm); ++i)
      cout << v[i];
    cout << endl;
  }
  return 0;
}
