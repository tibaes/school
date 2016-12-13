#include <bits/stdc++.h>

void f(std::set<std::string> &c, std::string &s) {
  c.insert(s);
  if (s.size() > 1) {
    for (uint i = 0; i < s.size(); ++i) {
      auto s_minus_one = s;
      s_minus_one.erase(i, 1);
      if (c.find(s_minus_one) == c.end())
        f(c, s_minus_one);
    }
  }
}

int main() {
  std::string s;
  while (std::cin >> s) {
    std::set<std::string> c;
    f(c, s);
    for (auto i = c.begin(); i != c.end(); ++i) {
      std::cout << *i << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
