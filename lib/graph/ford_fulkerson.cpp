#include "../template.cpp"

template<typename T>
struct FordFulkerson {
    // O(FE)
    struct edge {
        int to, rev;
        T cap;
        edge(int to, T cap, int rev) :
            to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> g;
    vector<int> used;
    const T INF;
    int timestamp;

    FordFulkerson(int n) :
        INF(numeric_limits<T>::max()),
        timestamp(0), g(n), used(n, -1) {}

    void add_edge(int s, int t, T cap) {
        g[s].emplace_back(t, cap, (int)g[t].size());
        g[t].emplace_back(s,   0, (int)g[s].size() - 1);
    }

    T dfs(int v, const int t, T flow) {
        if (v == t) return flow;
        used[v] = timestamp;
        for (edge &e : g[v]) {
            if (e.cap > 0 and used[e.to] != timestamp) {
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
        for (T f; (f = dfs(s, t, INF)) > 0; timestamp++) {
            flow += f;
        }
        return flow;
    }
};
