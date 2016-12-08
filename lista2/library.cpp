#include <bits/stdc++.h>

int main() {
  int N;
  while (std::cin >> N) {
    std::vector<int> books;
    while (N--) {
      int code;
      std::cin >> code;
      books.push_back(code);
    }
    std::sort(books.begin(), books.end());
    for (auto b = books.begin(); b != books.end(); ++b)
      std::cout << std::setfill('0') << std::setw(4) << *b << std::endl;
  }
  return 0;
}
