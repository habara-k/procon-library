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


# :x: test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f108cdd252ebfc58a7b9bc5c4c206374">test/graph/heavy_light_decomposition</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 13:35:37+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E</a>


## Depends on

* :question: <a href="../../../../library/lib/graph/heavy_light_decomposition.cpp.html">lib/graph/heavy_light_decomposition.cpp</a>
* :question: <a href="../../../../library/lib/structure/lazy_segment_tree.cpp.html">lib/structure/lazy_segment_tree.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../../../lib/graph/heavy_light_decomposition.cpp"
#include "../../../lib/structure/lazy_segment_tree.cpp"

int main()
{
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        G[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }

    HLDecomposition hld(G);
    hld.build();

    LazySegmentTree<LL> segt(
            n, 0, 0,
            [](LL a,LL b){ return a+b; },
            [](LL a,LL b,int w){ return a+b*w; },
            [](LL a,LL b){ return a+b; });

    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 0) {
            int v, w; cin >> v >> w;
            hld.update(0, v, [&](int a,int b){ segt.update(a,b,w); }, true);
        }
        if (c == 1) {
            int v; cin >> v;
            LL ret = hld.query(0, v,
                    [&](int a,int b){ return segt.query(a,b); },
                    [&](LL a,LL b){ return a+b; }, 0LL, true);
            cout << ret << endl;
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

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

#line 2 "lib/graph/heavy_light_decomposition.cpp"

struct HLDecomposition {
    const vector<vector<int>>& G;
    vector<int> par, size, depth, head, vid;
    // par[v]: parent of v
    // size[v]: size of subtree[v]
    // depth[v]: depth of v. depth[root] = 0
    // head[v]: head of row containing v
    // vid[v]: index of v when all the rows are aligned.

    void dfs(int v, int p, int d) {
        par[v] = p; depth[v] = d; size[v] = 1;
        for (int u : G[v]) {
            if (u == p) continue;
            dfs(u, v, d+1);
            size[v] += size[u];
        }
    }
    void hld(int v, int h, int& k) {
        head[v] = h; vid[v] = k++;
        int ma = 0, id = -1;
        for (int u : G[v]) {
            if (u == par[v]) continue;
            if (chmax(ma, size[u])) id = u;
        }
        if (id == -1) return;
        hld(id, h, k);
        for (int u : G[v]) {
            if (u == id || u == par[v]) continue;
            hld(u, u, k);
        }
    }

    HLDecomposition(const vector<vector<int>>& g) :
        G(g), par(g.size()), size(g.size()), depth(g.size()),
        head(g.size()), vid(g.size()) {}

    void build(int root = 0) {
        dfs(root, -1, 0);
        int k = 0;
        hld(root, root, k);
    }

    int lca(int u, int v) {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (depth[u] > depth[v]) swap(u, v);
                return u;
            }
        }
    }

    template<typename UpdateQuery>
    void update(int u, int v, const UpdateQuery& q, bool edge = false) {
        // q(a, b): update [a, b).
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                q(vid[u] + edge, vid[v] + 1);
                break;
            } else {
                q(vid[head[v]], vid[v] + 1);
            }
        }
    }

    template<typename Query, typename MergeFunc, typename T>
    T query(int u, int v, const Query& q, const MergeFunc& f, const T& ident, bool edge = false) {
        // q(a, b): return f[a, b).
        // f: 二つの区間の要素をマージする関数
        // ident: モノイドの単位元
        T ret = ident;
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                return f(ret, q(vid[u] + edge, vid[v] + 1));
            } else {
                ret = f(ret, q(vid[head[v]], vid[v] + 1));
            }
        }
    }
};
#line 2 "lib/structure/lazy_segment_tree.cpp"

template<typename M, typename OM = M>
struct LazySegmentTree {
    int sz;
    vector<M> data;
    vector<OM> lazy;
    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    const M e;
    const OM oe;
    // f: 二つの区間の要素をマージする関数
    // g: 要素と作用素をマージする二項演算. 第三引数は区間幅
    // h: 作用素をマージする関数
    // e: モノイドの単位元
    // oe: 作用素の単位元

    LazySegmentTree(
            int n,
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h,
            const M& e, const OM& oe
            ) : f(f), g(g), h(h), e(e), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
        lazy.assign(2*sz, oe);
    }

    void build(const vector<M>& v) {
        assert(v.size() <= sz);
        for (int i = 0; i < v.size(); ++i) {
            data[i + sz] = v[i];
        }
        for (int i = sz-1; i > 0; --i) {
            data[i] = f(data[2*i], data[2*i+1]);
        }
    }

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = h(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        }
        data[k] = g(data[k], lazy[k], len);
        lazy[k] = oe;
    }

    void _update(int a, int b, const OM &x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) return;
        else if (a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
        } else {
            _update(a, b, x, 2*k,   l, (l+r)/2);
            _update(a, b, x, 2*k+1, (l+r)/2, r);
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    void update(int a, int b, const OM &x) {
        // update [a, b) with x.
        _update(a, b, x, 1, 0, sz);
    }

    M _query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) return e;
        else if (a <= l && r <= b) return data[k];
        else return f(
                _query(a, b, 2*k,   l, (l+r)/2),
                _query(a, b, 2*k+1, (l+r)/2, r));
    }

    M query(int a, int b) {
        // return f[a, b).
        return _query(a, b, 1, 0, sz);
    }
};
#line 5 "test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp"

int main()
{
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        G[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }

    HLDecomposition hld(G);
    hld.build();

    LazySegmentTree<LL> segt(
            n, 0, 0,
            [](LL a,LL b){ return a+b; },
            [](LL a,LL b,int w){ return a+b*w; },
            [](LL a,LL b){ return a+b; });

    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int c; cin >> c;
        if (c == 0) {
            int v, w; cin >> v >> w;
            hld.update(0, v, [&](int a,int b){ segt.update(a,b,w); }, true);
        }
        if (c == 1) {
            int v; cin >> v;
            LL ret = hld.query(0, v,
                    [&](int a,int b){ return segt.query(a,b); },
                    [&](LL a,LL b){ return a+b; }, 0LL, true);
            cout << ret << endl;
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

