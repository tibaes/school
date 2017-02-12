#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<bool> resp(10010, false);
  for (int x = 0; x <= 100; ++x)
    for (int y = 0; y <= 100; ++y) {
      auto s = x * x + y * y;
      if (s > 10000)
        break;
      resp[s] = true;
    }
  int inp;
  while (cin >> inp)
    if (inp < 0)
      cout << "NO" << endl;
    else
      cout << ((resp[inp]) ? "YES" : "NO") << endl;
  return 0;
}
