#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306"

#include "../../../lib/graph/maximum_clique.cpp"

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<bool>> G(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) G[i][i] = true;

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int u, v, f; cin >> u >> v >> f; --u, --v;
        G[u][v] = G[v][u] = 1;
        g[u][v] = g[v][u] = f;
    }

    auto f = [&](const vector<int>& vs){
        int ret = 0;
        for (int i : vs) {
            int mi = 0;
            for (int j : vs) if (i != j) {
                if (mi == 0) mi = g[i][j];
                else chmin(mi, g[i][j]);
            }
            ret += mi;
        }
        return ret;
    };

    cout << maximum_clique<int>(G, f) << endl;

    return 0;
}
