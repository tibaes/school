#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int v, z;
  Edge(int vv, int zz) : v{vv}, z{zz} {};
  bool operator<(const Edge &e) const {
    return ((z == e.z) ? (v < e.v) : (z < e.z));
  }
};

// Using PRIM

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  while (cin >> m >> n && m && n) {
    long all_roads = 0;
    vector<vector<Edge>> adj(m);

    for (auto i = 0; i < n; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      all_roads += z;
      adj[x].push_back(Edge{y, z});
      adj[y].push_back(Edge{x, z});
    }

    long min_roads = 0;

    vector<bool> visited(m, false);
    visited[0] = true;

    set<Edge> visited_adj;
    visited_adj.insert(adj[0].begin(), adj[0].end());

    while (visited_adj.size() > 0) {
      while (visited_adj.size() > 0 && visited[visited_adj.begin()->v])
        visited_adj.erase(visited_adj.begin());

      if (visited_adj.size() <= 0)
        break;

      min_roads += visited_adj.begin()->z;
      auto v = visited_adj.begin()->v;

      visited[v] = true;
      for (const auto &a : adj[v])
        if (!visited[a.v])
          visited_adj.insert(a);
    }

    cout << (all_roads - min_roads) << endl;
  }

  return 0;
}
