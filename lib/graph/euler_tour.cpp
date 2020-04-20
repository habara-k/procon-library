#include "../template.cpp"

struct EulerTour {
    using G = vector<vector<int>>;
    const G& g;
    vector<int> ds, us;

    EulerTour(const G& g) :
        g(g), ds(g.size()), us(g.size()) {}

    void dfs(int v, int p, int& idx) {
        for (int u : g[v]) {
            if (u == p) continue;
            ds[u] = idx++;
            dfs(u, v, idx);
            us[u] = idx++;
        }
    }

    void build(int v) {
        int idx = 1;
        dfs(v, -1, idx);
        us[v] = 2 * g.size() - 1;
    }
};
