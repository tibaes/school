#include <bits/stdc++.h>

typedef struct Country {
  std::string name;
  int gold, silver, bronze;
} Country;

int main() {
  int N;
  std::cin >> N;
  std::vector<Country> list;
  while (N--) {
    int G, S, B;
    std::string CNAME;
    std::cin >> CNAME >> G >> S >> B;
    list.push_back(Country{CNAME, G, S, B});
  }

  std::sort(list.begin(), list.end(),
            [](const Country &a, const Country &b) -> bool {
              if (a.gold > b.gold)
                return true;
              if (a.gold == b.gold) {
                if (a.silver > b.silver)
                  return true;
                if (a.silver == b.silver) {
                  if (a.bronze > b.bronze)
                    return true;
                  if (a.bronze == b.bronze)
                    return (a.name.compare(b.name) < 0);
                }
              }
              return false;
            });

  for (auto l = list.begin(); l != list.end(); ++l)
    std::cout << l->name << " " << l->gold << " " << l->silver << " "
              << l->bronze << std::endl;

  return 0;
}
