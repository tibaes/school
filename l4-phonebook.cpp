#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<string> numbers;
    while (n--) {
      string nb;
      cin >> nb;
      numbers.push_back(nb);
    }
    sort(numbers.begin(), numbers.end());
    auto economy = 0;
    for (uint i = 1; i < numbers.size(); ++i) {
      uint c = 0;
      while (c < numbers[i].size() && numbers[i - 1][c] == numbers[i][c])
        c++;
      economy += c;
    }
    cout << economy << endl;
  }
  return 0;
}
