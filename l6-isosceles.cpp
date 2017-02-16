#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while ((cin >> n) && n > 0) {
    vector<int> heights;
    heights.reserve(n);
    vector<int> botton;
    botton.reserve(n);
    for (auto i = 0; i < n; ++i) {
      int a;
      cin >> a;
      heights.push_back(a);
      botton.push_back(i);
    }

    int maxH = 1;
    for (auto h = 2; h <= n; ++h) {
      vector<int> top;
      for (auto i = 2; i < (int)botton.size(); ++i) {
        auto x0 = botton[i - 2];
        auto x1 = botton[i - 1];
        auto x2 = botton[i];
        if ((x0 == x1 - 1) && (x1 == x2 - 1) && (heights[x1] >= h)) {
          top.push_back(x1);
        }
      }

      if (top.empty())
        break;
      else
        maxH = h;

      botton = top;
    }

    cout << maxH << endl;
  }
  return 0;
}
