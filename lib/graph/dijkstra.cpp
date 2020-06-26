#include "../template.cpp"
#include "./edge.cpp"

template<typename T>
vector<T> dijkstra(const Graph<T>& g, int s) {
    const T infty = numeric_limits<T>::max();
    vector<T> d(g.size(), infty);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
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
