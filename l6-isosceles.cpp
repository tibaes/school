#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a;
  while ((cin >> n) && n > 0) {
    vector<int> heights;
    heights.reserve(n);
    heights.push_back(1);
    cin >> a;
    for (auto i = 1; i < n; ++i) {
      cin >> a;
      auto p0 = min(i + 1, n - i);
      auto p1 = min(heights[i - 1] + 1, a);
      heights.push_back(min(p0, p1));
    }

    int maxH = 1;
    for (auto i = n - 2; i > 0; --i) {
      heights[i] = min(heights[i + 1] + 1, heights[i]);
      maxH = max(maxH, heights[i]);
    }

    cout << maxH << endl;
  }
  return 0;
}
