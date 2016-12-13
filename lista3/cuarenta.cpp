#include <bits/stdc++.h>

uint getIntersection(const std::vector<uint> &v,
                     const std::vector<uint> &index) {
  auto i = index.begin();
  uint intersection = v[*i];
  while (++i != index.end())
    intersection &= v[*i];
  return intersection;
}

void f(const uint k, const uint depth, const uint start,
       const std::vector<uint> &v, std::vector<uint> &index, uint &max) {
  if (k == depth) {
    auto t = getIntersection(v, index);
    if (t > max)
      max = t;
  } else {
    for (uint i = start; i < v.size(); ++i) {
      index[depth] = i;
      f(k, depth + 1, i + 1, v, index, max);
    }
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    uint n, k;
    std::cin >> n >> k;
    std::vector<uint> v;
    while (n--) {
      uint t;
      std::cin >> t;
      v.push_back(t);
    }

    std::vector<uint> index(k, 0);
    uint max = 0;
    f(k, 0, 0, v, index, max);

    std::cout << max << std::endl;
  }
  return 0;
}
