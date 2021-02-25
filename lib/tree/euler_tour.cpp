#include "../template.cpp"

struct EulerTour {
    vector<int> ds, us;
    vector<vector<int>> g;

    EulerTour(const vector<vector<int>>& g) :
        g(g), ds(g.size()), us(g.size()) {}

    void dfs(int u, int p, int& idx) {
        for (int v : g[u]) {
            if (v == p) continue;
            ds[v] = idx++;
            dfs(v, u, idx);
            us[v] = idx++;
        }
    }

    void build(int root=0) {
        int idx = 1;
        dfs(root, -1, idx);
        us[root] = 2 * g.size() - 1;
    }
};
