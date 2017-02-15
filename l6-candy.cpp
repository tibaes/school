#include <bits/stdc++.h>
using namespace std;

using LInt = long long int;

LInt optimizator(const vector<LInt> &line) {
  if (line.size() == 0)
    return 0;
  if (line.size() == 1)
    return line.front();
  if (line.size() == 2)
    return max(line.front(), line.back());
  vector<long long int> maximal(line.size(), 0);
  maximal[0] = line[0];
  maximal[1] = max(line[0], line[1]);
  for (uint i = 2; i < maximal.size(); ++i) {
    maximal[i] = max(maximal[i - 1], maximal[i - 2] + line[i]);
  }
  return maximal.back();
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  while ((cin >> m >> n) && m && n) {
    vector<LInt> optimizedLines;
    for (auto im = 0; im < m; ++im) {
      vector<LInt> line;
      for (auto in = 0; in < n; ++in) {
        int a;
        cin >> a;
        line.push_back(a);
      }
      optimizedLines.push_back(optimizator(line));
    }
    cout << optimizator(optimizedLines) << endl;
  }
  return 0;
}
