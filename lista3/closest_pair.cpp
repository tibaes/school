#include <bits/stdc++.h>

struct Point {
  int x, y;
};

struct Edge {
  Point a, b;
  double dist;
  bool operator<(const Edge &e) const { return (dist < e.dist); }
};

Edge euclidianDistance(const Point &a, const Point &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dist = std::sqrt(dx * dx + dy * dy);
  return Edge{a, b, dist};
}

Edge closestPairBruteForce(const std::vector<Point> &p) {
  Edge min;
  min.dist = std::numeric_limits<double>::max();
  for (uint i = 0; i < p.size() - 1; ++i) {
    for (uint j = i + 1; j < p.size(); ++j) {
      auto e = euclidianDistance(p[i], p[j]);
      if (e < min)
        min = e;
    }
  }
  return min;
}

Edge closestPairRec(const std::vector<Point> &Px,
                    const std::vector<Point> &Py) {
  if (Px.size() <= 3)
    return closestPairBruteForce(Px);

  const uint mean_x_id = Px.size() / 2;
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
      auto e = euclidianDistance(middle_y[i], middle_y[j]);
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
  return closestPairRec(sx, sy);
}

int main() { return 0; }
