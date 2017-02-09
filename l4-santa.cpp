#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<string> names;
    int good_behavior = 0;
    while (n--) {
      string id, nm;
      cin >> id >> nm;
      if (id.front() == '+')
        good_behavior++;
      names.push_back(nm);
    }
    sort(names.begin(), names.end());
    for (auto &nm : names)
      cout << nm << endl;
    cout << "Se comportaram: " << good_behavior
         << " | Nao se comportaram: " << int(names.size()) - good_behavior
         << endl;
  }
  return 0;
}
