#include "../template.cpp"

struct LowLink {
    const vector<vector<int>> g;
    const int sz;
    vector<int> ord, low, par;
    vector<int> used, is_articulation, is_bridge;

    LowLink(const vector<vector<int>>& g) :
        g(g), sz(g.size()), ord(sz), low(sz), used(sz),
        par(sz), is_articulation(sz), is_bridge(sz) {}

    void build(int root) {
        dfs(root, -1, 0);
    }

    void dfs(int v, int p, int k) {
        used[v] = 1;
        par[v] = p;
        low[v] = ord[v] = k++;
        int cnt = 0;
        for (int u : g[v]) {
            if (u == p) continue;
            if (!used[u]) {
                ++cnt;
                dfs(u, v, k);
                low[v] = min(low[v], low[u]);
                is_articulation[v] |= ord[v] <= low[u];
                is_bridge[u] |= ord[v] < low[u];
            } else {
                low[v] = min(low[v], ord[u]);
            }
        }
        if (p == -1) is_articulation[v] = cnt > 1;
    }
};
