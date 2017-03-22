#include <bits/stdc++.h>
using namespace std;

int LCS_Seq(string A, string B) {
  auto max_seq = 0;
  for (uint a = 0; a < A.length(); ++a) {
    for (uint b = 0; b < B.length(); ++b) {
      int i = 0;
      while (a + i < A.length() && b + i < B.length() && A[a + i] == B[b + i])
        ++i;
      max_seq = max(max_seq, i);
    }
  }
  return max_seq;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s1, s2;
  while (getline(cin, s1) && getline(cin, s2))
    cout << LCS_Seq(s1, s2) << endl;
  return 0;
}
