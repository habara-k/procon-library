#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../../lib/graph/primal_dual.cpp"

int main() {
    int n, m, f; cin >> n >> m >> f;
    PrimalDual<int,int> graph(n, numeric_limits<int>::max());
    for (int i = 0; i < m; ++i) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        graph.add_edge(u, v, c, d);
    }
    int ans = graph.min_cost_flow(0, n-1, f);
    cout << ans << endl;
}
