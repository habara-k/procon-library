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


# :heavy_check_mark: test/structure/segment_tree/rmq.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#971922f92a29e476633aa9737b609e73">test/structure/segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/segment_tree/rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-17 14:56:17+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/structure/segment_tree.cpp.html">lib/structure/segment_tree.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../../lib/structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> rmq(
            N,
            [&](int a, int b){ return min(a, b); },
            numeric_limits<int>::max());
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) rmq.update(X, [&](int x){ return Y; });
        else printf("%d\n", rmq.query(X, Y + 1));
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/segment_tree/rmq.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

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

#line 2 "lib/structure/segment_tree.cpp"

template<typename M>
struct SegmentTree {
    int sz;
    vector<M> data;
    const function<M(M,M)> f;
    const M e;

    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e
            ) : f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
    }

    template<typename UpdateQuery>
    void update(int k, const UpdateQuery& q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M _query(int a, int b, int k, int l, int r) {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return data[k];
        return f(_query(a,b,2*k,  l,(l+r)/2),
                 _query(a,b,2*k+1,(l+r)/2,r));
    }

    M query(int a, int b) {
        // return f[a,b)
        return _query(a, b, 1, 0, sz);
    }

    M operator[](int i) {
        return data.at(i + sz);
    }

    friend ostream& operator<<(ostream& os, const SegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.sz; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }
};
#line 4 "test/structure/segment_tree/rmq.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> rmq(
            N,
            [&](int a, int b){ return min(a, b); },
            numeric_limits<int>::max());
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) rmq.update(X, [&](int x){ return Y; });
        else printf("%d\n", rmq.query(X, Y + 1));
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

