#include "../template.cpp"

template<typename flow_t, typename cost_t>
struct PrimalDual {
    // O(FElogV)
    struct edge {
        int to, rev;
        flow_t cap;
        cost_t cost;
        edge(int to, flow_t cap, cost_t cost, int rev) :
                to(to), cap(cap), cost(cost), rev(rev) {}
    };

    vector<vector<edge>> g;
    const int sz;
    const cost_t INF;

    PrimalDual(int V, cost_t INF) : g(V), sz(V), INF(INF) {}

    void add_edge(int s, int t, flow_t cap, cost_t cost) {
        g[s].emplace_back(t, cap,  cost, (int)g[t].size());
        g[t].emplace_back(s,   0, -cost, (int)g[s].size() - 1);
    }

    void dijkstra(
            vector<cost_t>& dist,
            vector<int>& prevv,
            vector<int>& preve,
            const vector<cost_t>& potential, int s)
    {
        dist.assign(sz, INF);
        prevv.assign(sz, -1);
        preve.assign(sz, -1);
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> que;
        que.emplace(0, s);
        dist[s] = 0;
        while (!que.empty()) {
            cost_t cost; int v;
            std::tie(cost, v) = que.top();
            que.pop();
            if (dist[v] < cost) continue;
            for (int i = 0; i < g[v].size(); ++i) {
                edge &e = g[v][i];

                if (e.cost == INF or e.cost == -INF) continue;

                cost_t nextCost =
                        dist[v] + e.cost + potential[v] - potential[e.to];
                if (e.cap > 0 and dist[e.to] > nextCost) {
                    dist[e.to] = nextCost;
                    prevv[e.to] = v, preve[e.to] = i;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        cost_t ret = 0;
        vector<cost_t> potential(sz, 0);

        while (f > 0)
        {
            vector<cost_t> dist;
            vector<int> prevv, preve;
            dijkstra(dist, prevv, preve, potential, s);

            if (dist[t] == INF) return -1;

            for (int v = 0; v < sz; ++v) potential[v] += dist[v];

            flow_t diff = f;
            for (int v = t; v != s; v = prevv[v]) {
                diff = min(diff, g[prevv[v]][preve[v]].cap);
            }
            f -= diff;
            ret += diff * potential[t];

            for (int v = t; v != s; v = prevv[v]) {
                edge &e = g[prevv[v]][preve[v]], &re = g[v][e.rev];
                e.cap -= diff;
                re.cap += diff;
            }
        }

        return ret;
    }
};
