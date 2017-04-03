#include <bits/stdc++.h>
using namespace std;

int main() {
  // std::ios::sync_with_stdio(false);
  // cin.tie(NULL);
  int c, n;
  while (cin >> c >> n && c && n) {
    string c1, c2;
    getchar();
    getline(cin, c1);
    getline(cin, c2);

    map<char, char> key;
    for (auto i = 0; i < c; ++i) {
      char a = c1[i];
      char b = c2[i];
      if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z') {
        key[a] = b;
        key[b] = a;
        key[tolower(a)] = tolower(b);
        key[tolower(b)] = tolower(a);
      } else if (a >= 'A' && a <= 'Z') {
        key[tolower(a)] = b;
        key[a] = b;
        key[b] = tolower(a);
      } else if (b >= 'A' && b <= 'Z') {
        key[tolower(b)] = a;
        key[b] = a;
        key[a] = tolower(b);
      } else {
        key[a] = b;
        key[b] = a;
      }
    }

    for (auto i = 0; i < n; ++i) {
      string txt;
      getline(cin, txt);
      transform(txt.begin(), txt.end(), txt.begin(), [&](const char &c) {
        auto it = key.find(c);
        return ((it != key.end()) ? it->second : c);
      });
      cout << txt << endl;
    }

    cout << endl;
  }
  return 0;
}
