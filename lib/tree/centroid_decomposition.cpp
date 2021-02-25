#include "../template.cpp"

struct CentroidDecomposition {
    int n, root;
    vector<vector<int>> g, t;

    CentroidDecomposition(const vector<vector<int>>& g) :
    n(g.size()), g(g), t(n), sz(n), split(n) {
        root = build(0);
    }

private:
    vector<int> sz;
    vector<bool> split;

    int build_size(int u, int p) {
        sz[u] = 1;
        for (int v : g[u]) {
            if (v == p or split[v]) continue;
            sz[u] += build_size(v, u);
        }
        return sz[u];
    }
    int get_centroid(int u, int p, int mid) {
        for (int v : g[u]) {
            if (v == p or split[v]) continue;
            if (sz[v] > mid) return get_centroid(v, u, mid);
        }
        return u;
    }

    int build(int u) {
        int cent = get_centroid(u, -1, build_size(u, -1) / 2);
        split[cent] = true;
        for (int v : g[cent]) {
            if (!split[v]) t[cent].emplace_back(build(v));
        }
        split[cent] = false;
        return cent;
    }
};
