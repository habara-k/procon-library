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


# :heavy_check_mark: test/graph/lowlink/articulation.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f522f94949fa34ad9333addc4407bb3">test/graph/lowlink</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/lowlink/articulation.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-06 20:19:45+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"

#include "../../../lib/graph/lowlink.cpp"

int main()
{
    int V, E; cin >> V >> E;
    LowLink lowlink(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        lowlink.add_edge(s, t);
    }

    lowlink.build();

    sort(lowlink.articulations.begin(), lowlink.articulations.end());
    for (int v : lowlink.articulations) {
        cout << v << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/lowlink/articulation.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"

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

#line 2 "lib/graph/lowlink.cpp"

struct LowLink {
    struct edge {
        int to, rev, used;
        edge(int to, int rev) :
            to(to), rev(rev), used(0) {}
    };
    // e.used: used for down in dfs.
    vector<vector<edge>> g;
    const int sz;
    vector<int> ord, low, par;
    vector<int> used, _is_articulation;
    vector<int> articulations;
    vector<pair<int,int>> bridges;

    LowLink(int sz) :
        sz(sz), g(sz), ord(sz), low(sz), used(sz),
        par(sz), _is_articulation(sz) {}

    void add_edge(int u, int v) {
        g[u].emplace_back(v, (int)g[v].size());
        g[v].emplace_back(u, (int)g[u].size() - 1);
    }

    void build() {
        int k = 0;
        for (int i = 0; i < sz; ++i) {
            if (!used[i]) dfs(i, -1, k);
        }
    }

    void dfs(int v, int p, int& k) {
        used[v] = 1;
        par[v] = p;
        low[v] = ord[v] = k++;
        int cnt = 0;
        for (auto& e : g[v]) {
            int to = e.to;
            if (!used[to]) {
                e.used = 1;
                ++cnt;
                dfs(to, v, k);
                low[v] = min(low[v], low[to]);
                _is_articulation[v] |= ord[v] <= low[to];
                if (ord[v] < low[to]) {
                    bridges.emplace_back(minmax(to, v));
                }
            } else if (!g[to][e.rev].used) {
                low[v] = min(low[v], ord[to]);
            }
        }
        if (p == -1) _is_articulation[v] = cnt > 1;
        if (_is_articulation[v]) articulations.push_back(v);
    }

    bool is_articulation(int v) const { return _is_articulation[v]; }
    bool is_bridge(int u, int v) const {
        if (u != par[v] and v != par[u]) return false;
        if (u == par[v]) swap(u, v);
        return ord[v] < low[u];
    }
};
#line 4 "test/graph/lowlink/articulation.test.cpp"

int main()
{
    int V, E; cin >> V >> E;
    LowLink lowlink(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        lowlink.add_edge(s, t);
    }

    lowlink.build();

    sort(lowlink.articulations.begin(), lowlink.articulations.end());
    for (int v : lowlink.articulations) {
        cout << v << endl;
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

