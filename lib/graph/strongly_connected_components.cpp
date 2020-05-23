#include "../template.cpp"

struct StronglyConnectedComponents {
    int n;
    vector<vector<int>> g, rg, graph;
    vector<int> ord, used, comp;

    StronglyConnectedComponents(const vector<vector<int>>& g) :
            n(g.size()), g(g), rg(n), used(n), comp(n, -1)
    {
        for (int i = 0; i < n; ++i) {
            for (int to : g[i]) {
                rg[to].push_back(i);
            }
        }
    }

    void build() {
        for (int i = 0; i < n; ++i) dfs(i);
        reverse(ord.begin(), ord.end());
        int ptr = 0;
        for (int i : ord) if (comp[i] == -1) rdfs(i, ptr), ptr++;

        graph.resize(ptr);
        for (int i = 0; i < n; ++i) {
            for (int to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y) continue;
                graph[x].push_back(y);
            }
        }
        for (auto& v : graph) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }

private:
    void dfs(int idx) {
        if (used[idx]) return;
        used[idx] = true;
        for (int to : g[idx]) dfs(to);
        ord.push_back(idx);
    }

    void rdfs(int idx, int cnt) {
        if (comp[idx] != -1) return;
        comp[idx] = cnt;
        for (int to : rg[idx]) rdfs(to, cnt);
    }
};

