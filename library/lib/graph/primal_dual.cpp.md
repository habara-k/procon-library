---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: lib/graph/primal_dual.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/primal_dual.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-13 13:44:03+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/primal_dual/primal_dual.test.cpp.html">test/graph/primal_dual/primal_dual.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

    PrimalDual(int V) : g(V), sz(V), INF(numeric_limits<cost_t>::max()) {}

    void add_edge(int s, int t, flow_t cap, cost_t cost) {
        g[s].emplace_back(t, cap,  cost, (int)g[t].size());
        g[t].emplace_back(s,   0, -cost, (int)g[s].size() - 1);
    }

    void dijkstra(
            vector<cost_t>& dist,
            vector<int>& prevv,
            vector<int>& preve,
            const vector<int>& potential, int s)
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
                edge &e = g[prevv[v]][preve[v]];
                e.cap -= diff;
                g[v][e.rev].cap += diff;
            }
        }

        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/template.cpp"


#include <bits/stdc++.h>
using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}

// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

// std::vector Declaration and Initialization
template<typename T>
vector<T> make_vector(size_t a, T x) { return vector<T>(a, x); }
template<typename T, typename U, typename... Ts>
auto make_vector(size_t a, U b, Ts... ts) {
    return vector<decltype(make_vector<T>(b,ts...))>(a, make_vector<T>(b, ts...));
}

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) is >> e;
    return is;
}

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::array Debug
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::deque Debug
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& d) {
    os << "[";
    bool a = 1;
    for (auto e : d) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::multiset Debug
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool a = 1;
    for (auto e : mp) {
        os << (a ? "" : " ");
        os << e.first << ":" << e.second;
        a = 0;
    }
    os << "}";
    return os;
}

// std::tuple Debug
template<int N, class Tuple>
void out(ostream& os, const Tuple& t){}
template<int N, class Tuple, class H, class ...Ts>
void out(ostream& os, const Tuple& t) {
    if (N) os << " ";
    os << get<N>(t);
    out<N+1,Tuple,Ts...>(os, t);
}
template<class ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0,tuple<Ts...>,Ts...>(os, t);
    os << ")";
    return os;
}

// Debug
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

// Weighted edge
template<typename T>
struct edge {
    int src, to;
    T cost;

    edge() {}
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

using LL = int64_t;

#define fs first
#define sc second

const int64_t MOD = 1e9+7;

#line 2 "lib/graph/primal_dual.cpp"

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

    PrimalDual(int V) : g(V), sz(V), INF(numeric_limits<cost_t>::max()) {}

    void add_edge(int s, int t, flow_t cap, cost_t cost) {
        g[s].emplace_back(t, cap,  cost, (int)g[t].size());
        g[t].emplace_back(s,   0, -cost, (int)g[s].size() - 1);
    }

    void dijkstra(
            vector<cost_t>& dist,
            vector<int>& prevv,
            vector<int>& preve,
            const vector<int>& potential, int s)
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
                edge &e = g[prevv[v]][preve[v]];
                e.cap -= diff;
                g[v][e.rev].cap += diff;
            }
        }

        return ret;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

