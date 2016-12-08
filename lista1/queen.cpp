#include <bits/stdc++.h>

int main() {
  int x1, x2, y1, y2;

  while (std::cin >> x1 >> y1 >> x2 >> y2) {
    if (x1 + x2 + y1 + y2 == 0) {
      break;
    }

    int moves = -1;
    if (x1 == x2 && y1 == y2) {
      moves = 0;
    } else if (x1 == x2 || y1 == y2 || std::abs(x1 - x2) == std::abs(y1 - y2)) {
      moves = 1;
    } else {
      moves = 2;
    }

    std::cout << moves << std::endl;
  }
  return 0;
}
