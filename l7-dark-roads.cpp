#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int v, z;
  Edge(int vv, int zz) : v{vv}, z{zz} {}
  // bool operator<(const Edge &e) { return (this->z > e.z); } // inverse
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
      adj[x].push_back(Edge(y, z));
      adj[y].push_back(Edge(x, z));
    }

    // cout << "starting with: " << all_roads << endl;

    for (auto &a : adj) {
      sort(a.begin(), a.end(),
           [](const Edge &a, const Edge &b) { return (a.z > b.z); });
      /*cout << "# ";
      for (const auto b : a)
        cout << " (" << b.v << ", " << b.z << "); ";
      cout << endl;*/
    }

    long min_roads = 0;
    set<int> visited;
    visited.insert(0);

    vector<bool> fast_visited(m, false);
    fast_visited[0] = true;

    while (visited.size() < (uint)m) {
      /*
      cout << endl << "--- " << endl;
      for (const auto v : visited)
        cout << " " << v;
      cout << endl;*/

      int min_v = -1, min_z = -1;

      for (const auto v : visited) {
        while ((!adj[v].empty()) && (fast_visited[adj[v].back().v])) {
          adj[v].pop_back();
        }
        if (adj[v].empty())
          continue;

        /*cout << "# " << v << ": ";
        for (const auto b : adj[v])
          cout << " (" << b.v << ", " << b.z << "); ";
        cout << endl;*/

        if (min_z < 0 || adj[v].back().z < min_z) {
          min_z = adj[v].back().z;
          min_v = adj[v].back().v;
        }
      }

      min_roads += min_z;
      visited.insert(min_v);

      fast_visited[min_v] = true;

      /*cout << "growing with v " << min_v << ", z " << min_z << ": total "
           << min_roads << endl;*/
    }

    cout << (all_roads - min_roads) << endl;
  }

  return 0;
}
