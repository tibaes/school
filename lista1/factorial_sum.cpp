#include <bits/stdc++.h>

int main() {
  unsigned long long int M, N, FAT[21];
  FAT[0] = 1;
  for (int i = 1; i <= 20; ++i) {
    FAT[i] = FAT[i - 1] * i;
  }

  while (std::cin >> M >> N) {
    std::cout << FAT[M] + FAT[N] << std::endl;
  }

  return 0;
}
