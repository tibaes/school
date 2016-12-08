#include <bits/stdc++.h>

int main() {
  std::string name, is_friend, bff = "";
  std::set<std::string> friends, no_friends;

  while (true) {
    std::cin >> name;
    if (name.compare("FIM") == 0)
      break;

    std::cin >> is_friend;
    if (is_friend.compare("YES") == 0) {
      friends.insert(name);
      if (name.size() > bff.size())
        bff = name;
    } else
      no_friends.insert(name);
  }

  for (auto p = friends.begin(); p != friends.end(); ++p)
    std::cout << *p << std::endl;

  for (auto p = no_friends.begin(); p != no_friends.end(); ++p)
    std::cout << *p << std::endl;

  std::cout << std::endl << "Amigo do Habay:" << std::endl << bff << std::endl;

  return 0;
}
