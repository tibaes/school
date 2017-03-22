#include <bits/stdc++.h>
using namespace std;

string lowered(const string &s) {
  string r = s;
  transform(r.begin(), r.end(), r.begin(), ::tolower);
  return r;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  string max_raw, max_lower, str_raw, str_lower;
  getline(cin, max_raw);
  max_lower = lowered(max_raw);
  while (getline(cin, str_raw)) {
    str_lower = lowered(str_raw);
    if (max_lower.compare(str_lower) < 0) {
      max_lower = str_lower;
      max_raw = str_raw;
    }
  }
  cout << max_raw << endl;
  return 0;
}
