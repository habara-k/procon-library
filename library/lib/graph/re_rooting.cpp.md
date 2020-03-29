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


# :heavy_check_mark: lib/graph/re_rooting.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/re_rooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 12:22:32+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/re_rooting/re_rooting.test.cpp.html">test/graph/re_rooting/re_rooting.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename Data, typename T>
struct ReRooting {

    struct edge {
        int to, rev;
        Data data;
    };

    using F1 = function<T(T, T)>;
    using F2 = function<T(T, Data)>;

    vector<vector<edge>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const T init;

    ReRooting(int n, const F1 &f1, const F2 &f2, const T &init) :
        g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), init(init) {}

    void add_edge(int u, int v, const Data &d) {
        g[u].emplace_back((edge){v, (int)g[v].size(), d});
        g[v].emplace_back((edge){u, (int)g[u].size()-1, d});
    }

    T dfs(int idx, int par) {

        while (lptr[idx] != par and lptr[idx] < g[idx].size()) {
            auto &e = g[idx][lptr[idx]];
            ldp[idx][lptr[idx]+1] = f1(
                    ldp[idx][lptr[idx]],
                    f2(dfs(e.to, e.rev), e.data));
            ++lptr[idx];
        }
        while (rptr[idx] != par and rptr[idx] >= 0) {
            auto &e = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(
                    rdp[idx][rptr[idx]+1],
                    f2(dfs(e.to, e.rev), e.data));
            --rptr[idx];
        }
        if (par < 0) return rdp[idx][0];
        return f1(ldp[idx][par], rdp[idx][par+1]);
    }

    vector<T> solve() {
        for (int i = 0; i < g.size(); i++) {
            ldp[i].assign(g[i].size()+1, init);
            rdp[i].assign(g[i].size()+1, init);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size()-1;
        }
        vector<T> ret(g.size());
        for(int i = 0; i < g.size(); i++) {
            ret[i] = dfs(i, -1);
        }
        return ret;
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

#line 2 "lib/graph/re_rooting.cpp"

template<typename Data, typename T>
struct ReRooting {

    struct edge {
        int to, rev;
        Data data;
    };

    using F1 = function<T(T, T)>;
    using F2 = function<T(T, Data)>;

    vector<vector<edge>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const T init;

    ReRooting(int n, const F1 &f1, const F2 &f2, const T &init) :
        g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), init(init) {}

    void add_edge(int u, int v, const Data &d) {
        g[u].emplace_back((edge){v, (int)g[v].size(), d});
        g[v].emplace_back((edge){u, (int)g[u].size()-1, d});
    }

    T dfs(int idx, int par) {

        while (lptr[idx] != par and lptr[idx] < g[idx].size()) {
            auto &e = g[idx][lptr[idx]];
            ldp[idx][lptr[idx]+1] = f1(
                    ldp[idx][lptr[idx]],
                    f2(dfs(e.to, e.rev), e.data));
            ++lptr[idx];
        }
        while (rptr[idx] != par and rptr[idx] >= 0) {
            auto &e = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(
                    rdp[idx][rptr[idx]+1],
                    f2(dfs(e.to, e.rev), e.data));
            --rptr[idx];
        }
        if (par < 0) return rdp[idx][0];
        return f1(ldp[idx][par], rdp[idx][par+1]);
    }

    vector<T> solve() {
        for (int i = 0; i < g.size(); i++) {
            ldp[i].assign(g[i].size()+1, init);
            rdp[i].assign(g[i].size()+1, init);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size()-1;
        }
        vector<T> ret(g.size());
        for(int i = 0; i < g.size(); i++) {
            ret[i] = dfs(i, -1);
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

