#include "../template.cpp"

template<typename T>
T maximum_clique(
        vector<vector<bool>> G,
        const function<T(const vector<int>&)>& f) {

    // O(2^sqrt(2M) N) ?

    // G: undirected graph (matrix)
    // f: return max(f(clique set))

    T ret = numeric_limits<T>::min();

    int n = G.size();
    vector<int> deg(n);
    int M = 0;  // |edge|
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (G[i][j]) ++deg[i], ++deg[j], ++M;
        }
    }
    vector<bool> used(n);

    int lim = sqrt(2*M);

    while (true) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] and deg[i] < lim) {
                u = i;
                used[u] = true;
                break;
            }
        }

        vector<int> neighbor;
        if (u != -1) neighbor.push_back(u);
        for (int v = 0; v < n; ++v) if (!used[v]) {
            if (u == -1 || G[u][v]) {
                neighbor.push_back(v);
            }
        }

        int sz = neighbor.size();
        vector<int> bit(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (G[neighbor[i]][neighbor[j]]) {
                    bit[i] |= 1 << j;
                }
            }
        }

        vector<bool> dp(1<<sz);
        dp[0] = true;
        for (int s = 1; s < 1<<sz; ++s) {
            int i = __builtin_ffs(s) - 1;
            dp[s] = dp[s & ~(1<<i)] and (~bit[i] & s) == 0;
            if (dp[s]) {
                vector<int> vs;
                for (int i = 0; i < sz; ++i) if (s >> i & 1) {
                    vs.push_back(neighbor[i]);
                }
                ret = max(ret, f(vs));
            }
        }

        if (u == -1) break;

        for (int v : neighbor) {
            --deg[v], --deg[u];
            G[u][v] = G[v][u] = false;
        }
    }

    return ret;
}
