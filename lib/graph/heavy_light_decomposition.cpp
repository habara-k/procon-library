#include "./template.cpp"

struct HLDecomposition {
    const vector<vector<int>>& G;
    vector<int> par, size, depth, head, vid;
    // par[v]: parent of v
    // size[v]: size of subtree[v]
    // depth[v]: depth of v. depth[root] = 0
    // head[v]: head of row containing v
    // vid[v]: index of v when all the rows are aligned.

    void dfs(int v, int p, int d) {
        par[v] = p; depth[v] = d; size[v] = 1;
        for (int u : G[v]) {
            if (u == p) continue;
            dfs(u, v, d+1);
            size[v] += size[u];
        }
    }
    void hld(int v, int h, int& k) {
        head[v] = h; vid[v] = k++;
        int ma = 0, id = -1;
        for (int u : G[v]) {
            if (u == par[v]) continue;
            if (chmax(ma, size[u])) id = u;
        }
        if (id == -1) return;
        hld(id, h, k);
        for (int u : G[v]) {
            if (u == id or u == par[v]) continue;
            hld(u, u, k);
        }
    }

    HLDecomposition(const vector<vector<int>>& g) :
        G(g), par(g.size()), size(g.size()), depth(g.size()),
        head(g.size()), vid(g.size()) {}

    void build(int root = 0) {
        dfs(root, -1, 0);
        int k = 0;
        hld(root, root, k);
    }

    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (depth[u] > depth[v]) swap(u, v);
                return u;
            }
        }
    }

    template<typename UpdateQuery>
    void update(int u, int v, const UpdateQuery& q, bool edge = false) const {
        // q(a, b): update [a, b).
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                q(vid[u] + edge, vid[v] + 1);
                break;
            } else {
                q(vid[head[v]], vid[v] + 1);
            }
        }
    }

    template<typename Query, typename MergeFunc, typename T>
    T query(int u, int v,
            const Query& q, const MergeFunc& f,
            const T& ident, bool edge = false) const {
        // q(a, b): return f[a, b).
        // f: 二つの区間の要素をマージする関数
        // ident: モノイドの単位元
        T ret = ident;
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                return f(ret, q(vid[u] + edge, vid[v] + 1));
            } else {
                ret = f(ret, q(vid[head[v]], vid[v] + 1));
            }
        }
    }
};
