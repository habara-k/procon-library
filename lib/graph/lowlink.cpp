#include "../template.cpp"

struct LowLink {
    struct edge {
        int to, rev, used;
        edge(int to, int rev) :
            to(to), rev(rev), used(0) {}
    };
    // e.used: used for down in dfs.
    vector<vector<edge>> g;
    const int sz;
    vector<int> ord, low, par;
    vector<int> used, _is_articulation;
    vector<int> articulations;
    vector<pair<int,int>> bridges;

    LowLink(int sz) :
        sz(sz), g(sz), ord(sz), low(sz), used(sz),
        par(sz), _is_articulation(sz) {}

    void add_edge(int u, int v) {
        g[u].emplace_back(v, (int)g[v].size());
        g[v].emplace_back(u, (int)g[u].size() - 1);
    }

    void build() {
        int k = 0;
        for (int i = 0; i < sz; ++i) {
            if (!used[i]) dfs(i, -1, k);
        }
    }

    void dfs(int v, int p, int& k) {
        used[v] = 1;
        par[v] = p;
        low[v] = ord[v] = k++;
        int cnt = 0;
        for (auto& e : g[v]) {
            int to = e.to;
            if (!used[to]) {
                e.used = 1;
                ++cnt;
                dfs(to, v, k);
                low[v] = min(low[v], low[to]);
                _is_articulation[v] |= ord[v] <= low[to];
                if (ord[v] < low[to]) {
                    bridges.emplace_back(minmax(to, v));
                }
            } else if (!g[to][e.rev].used) {
                low[v] = min(low[v], ord[to]);
            }
        }
        if (p == -1) _is_articulation[v] = cnt > 1;
        if (_is_articulation[v]) articulations.push_back(v);
    }

    bool is_articulation(int v) const { return _is_articulation[v]; }
    bool is_bridge(int u, int v) const {
        if (u != par[v] and v != par[u]) return false;
        if (u == par[v]) swap(u, v);
        return ord[v] < low[u];
    }
};
