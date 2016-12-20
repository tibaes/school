#include <bits/stdc++.h>

struct Point {
  double x, y;
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

struct Edge {
  Point a, b;
  double dist;
  bool operator<(const Edge &e) const { return (dist < e.dist); }
};

std::ostream &operator<<(std::ostream &os, const Edge &e) {
  os << "a: " << e.a << ", b: " << e.b << ", dist: " << e.dist;
  return os;
}

Edge dotDistance(const Point &a, const Point &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dist = dx * dx + dy * dy;
  return Edge{a, b, dist};
}

Edge closestPairBruteForce(const std::vector<Point> &p) {
  Edge min;
  min.dist = std::numeric_limits<double>::max();
  for (uint i = 0; i < p.size() - 1; ++i) {
    for (uint j = i + 1; j < p.size(); ++j) {
      auto e = dotDistance(p[i], p[j]);
      if (e < min)
        min = e;
    }
  }
  return min;
}

Edge closestPairRec(const std::vector<Point> &Px,
                    const std::vector<Point> &Py) {
  /*
std::cout << "###############" << std::endl;
for (auto p : Px)
std::cout << p << " | ";
std::cout << std::endl;
for (auto p : Py)
std::cout << p << " | ";
std::cout << std::endl;
*/
  if (Px.size() <= 3)
    return closestPairBruteForce(Px);

  const uint mean_x_id = (Px.size() + 1) / 2;
  const auto qx = std::vector<Point>(Px.begin(), Px.begin() + mean_x_id);
  const auto rx = std::vector<Point>(Px.begin() + mean_x_id, Px.end());

  std::vector<Point> qy, ry;
  for (const auto &pt : Py) {
    if (pt.x <= qx.back().x)
      qy.push_back(pt);
    else
      ry.push_back(pt);
  }

  const auto q_min = closestPairRec(qx, qy);
  const auto r_min = closestPairRec(rx, ry);
  Edge min = (q_min < r_min) ? q_min : r_min;

  const double middle_x_range_min = qx.back().x - min.dist;
  const double middle_x_range_max = qx.back().x + min.dist;

  std::vector<Point> middle_y;
  for (const auto &pt : Py)
    if (pt.x >= middle_x_range_min && pt.x <= middle_x_range_max)
      middle_y.push_back(pt);

  for (uint i = 0; i < middle_y.size() - 1; ++i)
    for (uint j = i + 1; j < middle_y.size() && (j - i) <= 15; ++j) {
      auto e = dotDistance(middle_y[i], middle_y[j]);
      if (e < min)
        min = e;
    }

  return min;
}

Edge closestPair(const std::vector<Point> &p) {
  auto sx = p;
  std::sort(sx.begin(), sx.end(),
            [](const Point &a, const Point &b) { return (a.x < b.x); });
  auto sy = sx;
  std::sort(sy.begin(), sy.end(),
            [](const Point &a, const Point &b) { return (a.y < b.y); });
  auto e = closestPairRec(sx, sy);
  e.dist = std::sqrt(e.dist);
  return e;
}

int main() {
  std::vector<Point> in;
  int N;
  while (std::cin >> N && N > 0) {
    while (N--) {
      double x, y;
      std::cin >> x >> y;
      in.push_back(Point{x, y});
    }
    Edge e;
    if (in.size() > 1 && (e = closestPair(in)).dist < 10000)
      std::cout << std::fixed << std::setprecision(4) << e.dist << std::endl;
    else
      std::cout << "INFINITY" << std::endl;
  }
  return 0;
}
