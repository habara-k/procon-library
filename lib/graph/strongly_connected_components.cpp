#include "./template.cpp"

struct StronglyConnectedComponents {
    vector<vector<int>> g, rg, t;
    vector<int> comp, ord, used;

    StronglyConnectedComponents(const vector<vector<int>>& g) :
        g(g), rg(g.size()), comp(g.size(), -1), used(g.size())
    {
        for (int i = 0; i < g.size(); ++i) {
            for (int to : g[i]) {
                rg[to].push_back(i);
            }
        }
    }

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

    void build() {
        for (int i = 0; i < g.size(); ++i) dfs(i);
        reverse(ord.begin(), ord.end());
        int ptr = 0;
        for (int i : ord) if (comp[i] == -1) rdfs(i, ptr), ptr++;

        t.resize(ptr);
        for (int i = 0; i < g.size(); ++i) {
            for (int to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y) continue;
                t[x].push_back(y);
            }
        }
    }
};
