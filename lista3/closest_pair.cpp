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

Edge closestPairBruteForce(const std::vector<Point> &p, uint begin, uint end) {
  Edge min;
  min.dist = std::numeric_limits<double>::max();
  for (uint i = begin; i < end - 1; ++i) {
    for (uint j = i + 1; j < end; ++j) {
      auto e = dotDistance(p[i], p[j]);
      if (e < min)
        min = e;
    }
  }
  return min;
}

void msUnionSortedY(std::vector<Point> &P, uint begin, uint end, uint mean) {
  std::vector<Point> sorted_y;
  sorted_y.reserve(end - begin);
  uint q_id = begin, r_id = mean;
  while (q_id < mean || r_id < end) {
    if (q_id >= mean) {
      while (r_id < end)
        sorted_y.push_back(P[r_id++]);
    } else if (r_id >= end) {
      while (q_id < mean)
        sorted_y.push_back(P[q_id++]);
    } else {
      if (P[q_id].y < P[r_id].y)
        sorted_y.push_back(P[q_id++]);
      else
        sorted_y.push_back(P[r_id++]);
    }
  }
  uint p_id = 0;
  for (const auto &s : sorted_y)
    P[begin + p_id++] = s;
}

Edge closestPairRec(std::vector<Point> &P, uint begin, uint end) {

  std::cout << "VVVV " << begin << " - " << end << std::endl;
  for (uint i = begin; i < end; ++i)
    std::cout << "- " << P[i] << std::endl;

  const auto size = end - begin;
  const auto mean = (begin + end + 1) / 2;
  const double mean_x = P[mean - 1].x;

  if (size <= 4) {
    std::sort(P.begin() + begin, P.begin() + end,
              [](const Point &a, const Point &b) { return (a.y < b.y); });
    return closestPairBruteForce(P, begin, end);
  }

  const auto q_min = closestPairRec(P, begin, mean);
  const auto r_min = closestPairRec(P, mean, end);
  Edge min = (q_min < r_min) ? q_min : r_min;

  std::cout << "^^^^ " << begin << " - " << end << std::endl;

  const double middle_x_range_min = mean_x - min.dist;
  const double middle_x_range_max = mean_x + min.dist;

  std::cout << "ms sort y" << std::endl;
  msUnionSortedY(P, begin, end, mean);

  std::cout << "middle y" << std::endl;
  std::vector<Point> middle_y;
  middle_y.reserve(size);
  for (uint i = begin; i < end; ++i)
    if (P[i].x >= middle_x_range_min && P[i].x <= middle_x_range_max)
      middle_y.push_back(P[i]);

  std::cout << "bf over middle y" << std::endl;
  for (uint i = 0; i < middle_y.size() - 1; ++i)
    for (uint j = i + 1; j < middle_y.size() && (j - i) <= 15; ++j) {
      auto e = dotDistance(middle_y[i], middle_y[j]);
      if (e < min)
        min = e;
    }

  std::cout << "local minima: " << min << std::endl;

  return min;
}

Edge closestPair(const std::vector<Point> &p) {
  auto sx = p;
  std::sort(sx.begin(), sx.end(),
            [](const Point &a, const Point &b) { return (a.x < b.x); });
  auto e = closestPairRec(sx, 0, sx.size());
  e.dist = std::sqrt(e.dist);
  return e;
}

int main() {
  int N = 0;
  while (std::cin >> N && N > 0) {
    std::vector<Point> in;
    in.reserve(N);
    while (N--) {
      double x, y;
      std::cin >> x >> y;
      in.push_back(Point{x, y});
    }
    const auto e = closestPair(in);
    if (e.dist < 10000.0)
      std::cout << std::fixed << std::setprecision(4) << e.dist << std::endl;
    else
      std::cout << "INFINITY" << std::endl;
  }
  return 0;
}
