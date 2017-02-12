#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int nc;
  cin >> nc;
  while (nc--) {
    int n;
    cin >> n;
    vector<uint> hist(231, 0);
    while (n--) {
      int h;
      cin >> h;
      hist[h]++;
    }
    stringstream pres;
    for (auto ih = 20; ih <= 230; ++ih)
      for (uint c = 0; c < hist[ih]; ++c)
        pres << ih << " ";
    auto out = pres.str();
    out.pop_back();
    cout << out << endl;
  }
  return 0;
}
