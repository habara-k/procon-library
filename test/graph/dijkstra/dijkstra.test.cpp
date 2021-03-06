#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../../lib/graph/dijkstra.cpp"

int main() {
    int V, E, R;
    cin >> V >> E >> R;
    vector<vector<edge<int>>> g(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }

    for (auto &dist : dijkstra(g, R)) {
        if (dist == numeric_limits<int>::max()) cout << "INF" << endl;
        else cout << dist << endl;
    }
}
