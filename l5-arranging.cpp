#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  while (cin >> N >> H) {
    vector<vector<int>> tasksHN(H + 1);
    int sumValues = 0;
    while (N--) {
      int v, t;
      cin >> v >> t;
      tasksHN[t].push_back(v);
      sumValues += v;
    }
    int maxRevenue = 0;
    for (int ih = H; ih > 0; --ih) {
      if (tasksHN[ih].empty())
        continue;
      if (tasksHN[ih].size() == 1) {
        maxRevenue += tasksHN[ih].front();
        continue;
      }
      auto it_max = max_element(tasksHN[ih].begin(), tasksHN[ih].end());
      maxRevenue += *it_max;
      swap(*it_max, tasksHN[ih].front());
      tasksHN[ih - 1].insert(tasksHN[ih - 1].end(), tasksHN[ih].begin() + 1,
                             tasksHN[ih].end());
    }
    cout << sumValues - maxRevenue << endl;
  }
  return 0;
}
