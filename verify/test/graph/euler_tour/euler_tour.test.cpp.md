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


# :heavy_check_mark: test/graph/euler_tour/euler_tour.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#69fd5ef22b7d7c3c4b992623880b61ab">test/graph/euler_tour</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/euler_tour/euler_tour.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/euler_tour.cpp.html">lib/graph/euler_tour.cpp</a>
* :question: <a href="../../../../library/lib/graph/template.cpp.html">lib/graph/template.cpp</a>
* :question: <a href="../../../../library/lib/structure/binary_indexed_tree.cpp.html">lib/structure/binary_indexed_tree.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../../lib/graph/euler_tour.cpp"
#include "../../../lib/structure/binary_indexed_tree.cpp"

int main() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; G[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }

    EulerTour tour(G);
    tour.build(0);

    BIT<int> bit(2*n);
    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 1) {
            int v; cin >> v;
            cout << bit.sum(tour.ds[v]) << endl;
        }
        if (c == 0) {
            int v, w; cin >> v >> w;
            bit.add(tour.ds[v], w);
            bit.add(tour.us[v], -w);
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/euler_tour/euler_tour.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

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


#line 2 "lib/graph/euler_tour.cpp"

struct EulerTour {
    using G = vector<vector<int>>;
    const G& g;
    vector<int> ds, us;

    EulerTour(const G& g) :
        g(g), ds(g.size()), us(g.size()) {}

    void dfs(int v, int p, int& idx) {
        for (int u : g[v]) {
            if (u == p) continue;
            ds[u] = idx++;
            dfs(u, v, idx);
            us[u] = idx++;
        }
    }

    void build(int v) {
        int idx = 1;
        dfs(v, -1, idx);
        us[v] = 2 * g.size() - 1;
    }
};
#line 2 "lib/structure/binary_indexed_tree.cpp"

template<typename T>
struct BIT {
    vector<T> data;
    int sz;
    BIT(int sz) : sz(sz), data(sz+1) {}

    void add(int i, T x) {
        // v[i] += x;
        assert(0 <= i and i < sz);
        for (++i; i < data.size(); i += i & -i) data[i] += x;
    }

    T sum(int i) const {
        // return v[0] + v[1] + ... + v[i]
        if (i < 0) return 0;
        assert(i < sz);
        T s = 0;
        for (++i; i > 0; i -= i & -i) s += data[i];
        return s;
    }

    friend ostream& operator<<(ostream& os, const BIT& b) {
        os << "[";
        for (int i = 0; i < b.sz; ++i) {
            if (i) os << " ";
            os << b.sum(i) - b.sum(i-1);
        }
        return os << "]";
    }
};
#line 5 "test/graph/euler_tour/euler_tour.test.cpp"

int main() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; G[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }

    EulerTour tour(G);
    tour.build(0);

    BIT<int> bit(2*n);
    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 1) {
            int v; cin >> v;
            cout << bit.sum(tour.ds[v]) << endl;
        }
        if (c == 0) {
            int v, w; cin >> v >> w;
            bit.add(tour.ds[v], w);
            bit.add(tour.us[v], -w);
        }
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

