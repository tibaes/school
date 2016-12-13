#include <bits/stdc++.h>

typedef struct Card {
  int a, d, h;
  Card operator+(const Card &c) const {
    Card acc{0, 0, 0};
    acc.a = a + c.a;
    acc.d = d + c.d;
    acc.h = h + c.h;
    return acc;
  };
  bool operator==(const Card &c) const {
    return (a == c.a && d == c.d && h == c.h);
  }
} Card;

bool f(const Card &target, const std::vector<Card> &cards,
       std::vector<bool> &valid, uint start = 0) {
  Card sum{0, 0, 0};
  int qt = 0;
  for (uint c = 0; c < cards.size(); c++) {
    if (valid[c]) {
      sum = sum + cards[c];
      qt++;
    }
  }
  if (sum == target && qt > 1)
    return true;

  for (uint c = start; c < cards.size(); c++) {
    if (valid[c]) {
      valid[c] = false;
      if (f(target, cards, valid, c + 1))
        return true;
      valid[c] = true;
    }
  }

  return false;
}

int main() {
  int n, a, d, h;
  std::cin >> n >> a >> d >> h;
  auto monster = Card{a, d, h};

  std::vector<Card> cards;
  while (n--) {
    std::cin >> a >> d >> h;
    cards.push_back(Card{a, d, h});
  }

  std::vector<bool> valid(cards.size(), 1);
  std::cout << ((f(monster, cards, valid)) ? "Y" : "N") << std::endl;

  return 0;
}
