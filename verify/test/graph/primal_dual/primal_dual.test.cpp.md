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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/graph/primal_dual/primal_dual.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cbce7cddb224a7f20c1a5382c41bc938">test/graph/primal_dual</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/primal_dual/primal_dual.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-22 14:55:46+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/primal_dual.cpp.html">lib/graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../../lib/graph/primal_dual.cpp"

int main() {
    int n, m, f; cin >> n >> m >> f;
    PrimalDual<int,int> graph(n, numeric_limits<int>::max());
    for (int i = 0; i < m; ++i) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        graph.add_edge(u, v, c, d);
    }
    int ans = graph.min_cost_flow(0, n-1, f);
    cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/primal_dual/primal_dual.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#line 1 "lib/template.cpp"


#include <bits/stdc++.h>
using namespace std;

// type {{{
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
// }}}


// macro {{{
#define REP(i,n) for (int i=0; i<(n); ++i)
#define RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i,a,n) for (int i=(a); i<(n); ++i)
#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)
// }}}


// debug {{{
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    REP (i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}
// }}}


// chmax, chmin {{{
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
// }}}


// constants {{{
#define inf(T) (numeric_limits<T>::max() / 2)
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
// }}}


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
#line 4 "test/graph/primal_dual/primal_dual.test.cpp"

int main() {
    int n, m, f; cin >> n >> m >> f;
    PrimalDual<int,int> graph(n, numeric_limits<int>::max());
    for (int i = 0; i < m; ++i) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        graph.add_edge(u, v, c, d);
    }
    int ans = graph.min_cost_flow(0, n-1, f);
    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

