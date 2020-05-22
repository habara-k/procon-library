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


# :heavy_check_mark: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#930708ccd228402100db5e002260e5b2">test/structure/persistent_segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-22 14:57:54+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/lowest_common_ancestor.cpp.html">lib/graph/lowest_common_ancestor.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/structure/persistent_segment_tree.cpp.html">lib/structure/persistent_segment_tree.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270"

#include "../../../lib/structure/persistent_segment_tree.cpp"
#include "../../../lib/graph/lowest_common_ancestor.cpp"

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // compress
    map<int,int> comp, comp_inv;
    for (auto X : x) comp[X] = -1;
    int comp_size = 0;
    for (auto &p : comp) {
        p.second = comp_size++;
    }
    for (auto p : comp) {
        comp_inv[p.second] = p.first;
    }

    // lca
    auto lca = LCA(G);

    // persistent segtree
    PersistentSegmentTree<int> segt(
            [](int a,int b){ return a+b; },
            0, comp.size());

    map<int,PersistentSegmentTree<int>::Node*> root;
    vector<int> par(N);

    function<void(int,int)> dfs = [&](int v, int p) {
        par[v] = p;
        root[v] = segt.update(root[p],
                comp[x[v]], [](int a){ return a+1; });
        for (int u : G[v]) {
            if (u != p) dfs(u, v);
        }
    };

    root[-1] = segt.build();
    dfs(0, -1);

    for (int i = 0; i < Q; ++i)
    {
        int v, w, l; cin >> v >> w >> l; --v, --w;

        // search x s.t. there are more than l numbers less than or equal to x

        int u = lca.query(v, w);

        auto check = [&](int m) {
            int nv = segt.query(root[v], 0, m+1),
                nw = segt.query(root[w], 0, m+1),
                nu = segt.query(root[u], 0, m+1),
                np = segt.query(root[par[u]], 0, m+1);

            return nv + nw - nu - np >= l;
        };

        int ng = -1, ok = comp.size()-1;
        while (abs(ok - ng) > 1) {
            int mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }

        cout << comp_inv[ok] << endl;
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270"

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


#line 2 "lib/structure/persistent_segment_tree.cpp"

template<typename M>
struct PersistentSegmentTree {
    struct Node {
        Node *l, *r;
        M data;
        Node() : l(nullptr), r(nullptr) {}
    };

    const function<M(M,M)> f;
    const M e;
    const int sz;

    PersistentSegmentTree(const function<M(M,M)>& f, const M& e, int sz) :
        f(f), e(e), sz(sz) {}

    Node* _new(const M& data) const {
        auto t = new Node();
        t->data = data;
        return t;
    }

    Node* _new(Node* l, Node* r) const {
        auto t = new Node();
        t->l = l, t->r = r, t->data = f(l->data, r->data);
        return t;
    }

    Node* _build(int l, int r) const {
        assert(l < r);
        if (l+1 == r) return _new(e);
        return _new(_build(l, (l+r)>>1), _build((l+r)>>1, r));
    }

    Node* build() const {
        return _build(0, sz);
    }

    template<typename UpdateQuery>
    Node* _update(Node* t, const UpdateQuery& q, int pos, int l, int r) const {
        if (pos == l and pos+1 == r) return _new(q(t->data));
        if (r <= pos or pos < l) return t;
        return _new(_update(t->l, q, pos, l, (l+r)>>1),
                    _update(t->r, q, pos, (l+r)>>1, r));
    }

    template<typename UpdateQuery>
    Node* update(Node* root, int pos, const UpdateQuery& q) const {
        return _update(root, q, pos, 0, sz);
    }

    M _query(Node* t, int a, int b, int l, int r) const {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return t->data;
        return f(_query(t->l, a, b, l, (l+r)>>1),
                 _query(t->r, a, b, (l+r)>>1, r));
    }

    M query(Node* root, int a, int b) const {
        // return f[a,b)
        return _query(root, a, b, 0, sz);
    }

};
#line 2 "lib/graph/lowest_common_ancestor.cpp"

struct LCA {
    int n, log2_n;
    vector<int> depth;
    vector<vector<int>> par;

    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        depth[v] = d;
        par[0][v] = p;
        for (auto to : G[v]) {
            if (to != p) dfs(G, to, v, d+1);
        }
    }

    LCA(const vector<vector<int>>& G, int root=0) :
            n(G.size()), log2_n(log2(n)), depth(n),
            par(log2_n+1, vector<int>(n,-1)) {

        dfs(G, root, -1, 0);
        for (int k = 0; k < log2_n; ++k) {
            for (int v = 0; v < n; ++v) {
                if (par[k][v] != -1) {
                    par[k+1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    int query(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v);

        // align the depth of u and v
        for (int k = 0; k <= log2_n; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = par[k][v];
            }
        }
        if (u == v) return u;

        // go back until u and v's parents do not match
        for (int k = log2_n; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
};
#line 5 "test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp"

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // compress
    map<int,int> comp, comp_inv;
    for (auto X : x) comp[X] = -1;
    int comp_size = 0;
    for (auto &p : comp) {
        p.second = comp_size++;
    }
    for (auto p : comp) {
        comp_inv[p.second] = p.first;
    }

    // lca
    auto lca = LCA(G);

    // persistent segtree
    PersistentSegmentTree<int> segt(
            [](int a,int b){ return a+b; },
            0, comp.size());

    map<int,PersistentSegmentTree<int>::Node*> root;
    vector<int> par(N);

    function<void(int,int)> dfs = [&](int v, int p) {
        par[v] = p;
        root[v] = segt.update(root[p],
                comp[x[v]], [](int a){ return a+1; });
        for (int u : G[v]) {
            if (u != p) dfs(u, v);
        }
    };

    root[-1] = segt.build();
    dfs(0, -1);

    for (int i = 0; i < Q; ++i)
    {
        int v, w, l; cin >> v >> w >> l; --v, --w;

        // search x s.t. there are more than l numbers less than or equal to x

        int u = lca.query(v, w);

        auto check = [&](int m) {
            int nv = segt.query(root[v], 0, m+1),
                nw = segt.query(root[w], 0, m+1),
                nu = segt.query(root[u], 0, m+1),
                np = segt.query(root[par[u]], 0, m+1);

            return nv + nw - nu - np >= l;
        };

        int ng = -1, ok = comp.size()-1;
        while (abs(ok - ng) > 1) {
            int mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }

        cout << comp_inv[ok] << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

