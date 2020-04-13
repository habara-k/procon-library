#include "../template.cpp"

template<typename T>
struct Dinic {
    // O(EV^2)
    struct edge {
        int to, rev;
        T cap;
        edge(int to, T cap, int rev) :
            to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> g;
    vector<int> level, iter;
    const T INF;

    Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}

    void add_edge(int s, int t, T cap) {
        g[s].emplace_back(t, cap, (int)g[t].size());
        g[t].emplace_back(s,   0, (int)g[s].size() - 1);
    }

    bool bfs(int s, int t) {
        level.assign(g.size(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : g[v]) {
                if (e.cap > 0 and level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    T dfs(int v, const int t, T flow) {
        if (v == t) return flow;
        for (int &i = iter[v]; i < g[v].size(); ++i) {
            edge &e = g[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            iter.assign(g.size(), 0);
            T f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};
