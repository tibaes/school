#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  while (cin >> str) {
    auto prefix = 0;
    while (!str.empty()) {
      stringstream out;
      for (auto i = 0; i < prefix; ++i)
        out << " ";
      out << str[0];
      for (uint i = 1; i < str.length(); ++i)
        out << " " << str[i];
      cout << out.str() << endl;
      str.pop_back();
      prefix++;
    }
    cout << endl;
  }
  return 0;
}
