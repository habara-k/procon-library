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


# :heavy_check_mark: lib/graph/ford_fulkerson.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/ford_fulkerson.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 20:05:03+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/ford_fulkerson/ford_fulkerson.test.cpp.html">test/graph/ford_fulkerson/ford_fulkerson.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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


#line 2 "lib/graph/ford_fulkerson.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
