#include "../template.cpp"

template<typename T>
vector<T> dijkstra(const vector<vector<edge<T>>>& g, int s) {
    const T inf = numeric_limits<T>::max();
    vector<T> d(g.size(), inf);

    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.emplace(d[s], s);
    while (!que.empty()) {
        auto [cost, v] = que.top();
        que.pop();
        if (d[v] < cost) continue;
        for (const auto &e : g[v]) {
            if (T alt = cost + e.cost; d[e.to] > alt) {
                d[e.to] = alt;
                que.emplace(alt, e.to);
            }
        }
    }
    return d;
}
