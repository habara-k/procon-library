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


# :heavy_check_mark: test/structure/lazy_segment_tree/rmq_raq.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7ce88e86f4e3cb938a6b6902ad70b7ea">test/structure/lazy_segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/lazy_segment_tree/rmq_raq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 00:26:32+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/structure/lazy_segment_tree.cpp.html">lib/structure/lazy_segment_tree.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<int64_t> tr(
            N,
            [](int64_t a, int64_t b){ return min(a, b); },
            [](int64_t a, int64_t b, int w){ return a + b; },
            [](int64_t a, int64_t b){ return a + b; },
            numeric_limits<int64_t>::max(), 0
            );

    tr.build(vector<int64_t>(N, 0));

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int64_t X;
            cin >> S >> T >> X;
            tr.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << tr.query(S, T+1) << endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/lazy_segment_tree/rmq_raq.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

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

#line 2 "lib/structure/lazy_segment_tree.cpp"

template<typename M, typename OM = M>
struct LazySegmentTree {
    int n, sz;
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
            ) : n(n), f(f), g(g), h(h), e(e), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
        lazy.assign(2*sz, oe);
    }

    void build(const vector<M>& v) {
        assert(v.size() <= n);
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

    void _update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
        } else {
            _update(a, b, x, 2*k,   l, (l+r)/2);
            _update(a, b, x, 2*k+1, (l+r)/2, r);
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    void update(int a, int b, const OM& x) {
        // update [a, b) with x.
        _update(a, b, x, 1, 0, sz);
    }

    M _query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return e;
        else if (a <= l and r <= b) return data[k];
        else return f(
                _query(a, b, 2*k,   l, (l+r)/2),
                _query(a, b, 2*k+1, (l+r)/2, r));
    }

    M query(int a, int b) {
        // return f[a, b).
        return _query(a, b, 1, 0, sz);
    }

    M operator[](int i) {
        return query(i, i+1);
    }

    friend ostream& operator<<(ostream& os, LazySegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }
};
#line 4 "test/structure/lazy_segment_tree/rmq_raq.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<int64_t> tr(
            N,
            [](int64_t a, int64_t b){ return min(a, b); },
            [](int64_t a, int64_t b, int w){ return a + b; },
            [](int64_t a, int64_t b){ return a + b; },
            numeric_limits<int64_t>::max(), 0
            );

    tr.build(vector<int64_t>(N, 0));

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int64_t X;
            cin >> S >> T >> X;
            tr.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << tr.query(S, T+1) << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

