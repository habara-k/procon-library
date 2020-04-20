#include "./lowlink.cpp"

struct TwoEdgeConnectedComponents {
    // require: undirected simple graph
    vector<vector<int>> t;
    vector<int> comp;
    LowLink lowlink;

    TwoEdgeConnectedComponents(const vector<vector<int>>& g) :
        lowlink(g), comp(g.size(), -1) {}

    void dfs(int v, int p, int& k) {
        if (p == -1 or lowlink.is_bridge(v, p)) comp[v] = k++;
        else comp[v] = comp[p];
        for (int to : lowlink.g[v]) {
            if (comp[to] == -1) dfs(to, v, k);
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
