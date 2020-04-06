#include "../template.cpp"

struct TwoEdgeConnectedComponents {
    vector<vector<int>> t;
    vector<int> comp;
    LowLink lowlink;

    TwoEdgeConnectedComponents(int sz) :
        comp(sz, -1), lowlink(sz) {}

    void add_edge(int u, int v) { lowlink.add_edge(u, v); }

    void dfs(int v, int p, int& k) {
        if (p == -1 or lowlink.is_bridge(v, p)) comp[v] = k++;
        else comp[v] = comp[p];
        for (const LowLink::edge& e : lowlink.g[v]) {
            if (comp[e.to] == -1) dfs(e.to, v, k);
        }
    }

    void build() {
        lowlink.build();
        int k = 0;
        for (int i = 0; i < comp.size(); ++i) {
            if (comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for (const auto& tp : lowlink.bridges) {
            int u = comp[tp.first], v = comp[tp.second];
            t[u].push_back(v);
            t[v].push_back(u);
        }
    }
};
