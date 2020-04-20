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
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :question: <a href="../../../../library/lib/graph/template.cpp.html">lib/graph/template.cpp</a>
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
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    LowLink lowlink(G);

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

#line 1 "lib/graph/template.cpp"


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


#line 4 "lib/graph/template.cpp"

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


#line 2 "lib/graph/lowlink.cpp"

struct LowLink {
    // require: undirected simple graph
    vector<vector<int>> g;
    const int sz;
    vector<int> ord, low, par;
    vector<int> used, _is_articulation;
    vector<int> articulations;
    vector<pair<int,int>> bridges;

    LowLink(const vector<vector<int>>& g) :
        g(g), sz(g.size()), ord(sz), low(sz), used(sz),
        par(sz), _is_articulation(sz) {}

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
        for (int to : g[v]) {
            if (!used[to]) {
                ++cnt;
                dfs(to, v, k);
                low[v] = min(low[v], low[to]);
                _is_articulation[v] |= ord[v] <= low[to];
                if (ord[v] < low[to]) {
                    bridges.emplace_back(minmax(to, v));
                }
            } else if (to != p) {
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
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    LowLink lowlink(G);

    lowlink.build();

    sort(lowlink.articulations.begin(), lowlink.articulations.end());
    for (int v : lowlink.articulations) {
        cout << v << endl;
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

