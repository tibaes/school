#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, l;
  cin >> t;
  while (t--) {
    long long int sum = 0;
    cin >> l;
    for (auto il = 0; il < l; ++il) {
      string s;
      cin >> s;
      for (uint is = 0; is < s.size(); ++is) {
        sum += s[is] - 'A';
        sum += il;
        sum += is;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
