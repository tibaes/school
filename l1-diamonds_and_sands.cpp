#include <bits/stdc++.h>

int main() {
  int N;
  std::cin >> N;
  while (N--) {
    std::string S;
    std::cin >> S;

    int diamonds = 0;
    int heads = 0;

    for (auto c = S.begin(); c != S.end(); c++) {
      if (*c == '<') {
        heads++;
      } else if (*c == '>' && heads > 0) {
        diamonds++;
        heads--;
      }
    }

    std::cout << diamonds << std::endl;
  }

  return 0;
}
