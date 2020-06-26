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


# :heavy_check_mark: test/graph/dijkstra/dijkstra.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#44397479ec27b867fc95e0f72cb70728">test/graph/dijkstra</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/dijkstra/dijkstra.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 12:56:23+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/dijkstra.cpp.html">lib/graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/graph/edge.cpp.html">lib/graph/edge.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../../lib/graph/edge.cpp"
#include "../../../lib/graph/dijkstra.cpp"

int main() {
    int V, E, R;
    cin >> V >> E >> R;
    vector<vector<edge<int>>> g(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({a,b,c});
    }

    for (auto &dist : dijkstra(g, R)) {
        if (dist == numeric_limits<int>::max()) puts("INF");
        else cout << dist << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/dijkstra/dijkstra.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#line 1 "lib/graph/edge.cpp"


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


#line 4 "lib/graph/edge.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 3 "lib/graph/dijkstra.cpp"

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
#line 5 "test/graph/dijkstra/dijkstra.test.cpp"

int main() {
    int V, E, R;
    cin >> V >> E >> R;
    vector<vector<edge<int>>> g(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({a,b,c});
    }

    for (auto &dist : dijkstra(g, R)) {
        if (dist == numeric_limits<int>::max()) puts("INF");
        else cout << dist << endl;
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

