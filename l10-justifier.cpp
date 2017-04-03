#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  bool first = true;
  while (cin >> n && n) {
    if (!first)
      cout << endl;
    first = false;

    uint max_word = 0;
    vector<string> words;
    for (auto i = 0; i < n; ++i) {
      string s;
      cin >> s;
      words.push_back(s);
      max_word = max(max_word, (uint)s.length());
    }

    for (const auto &w : words) {
      auto delta = max_word - (uint)w.length();
      if (delta == 0) {
        cout << w << endl;
        continue;
      }
      stringstream s;
      while (delta-- > 0)
        s << " ";
      s << w;
      cout << s.str() << endl;
    }
  }
  return 0;
}
