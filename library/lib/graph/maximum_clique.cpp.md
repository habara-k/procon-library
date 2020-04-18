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


# :heavy_check_mark: lib/graph/maximum_clique.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/maximum_clique.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-13 13:44:03+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/maximum_clique/maximum_clique.test.cpp.html">test/graph/maximum_clique/maximum_clique.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename T>
T maximum_clique(
        vector<vector<bool>> G,
        const function<T(const vector<int>&)>& f) {

    // O(2^sqrt(2M) N) ?

    // G: undirected graph (matrix)
    // f: return max(f(clique set))

    T ret = numeric_limits<T>::min();

    int n = G.size();
    vector<int> deg(n);
    int M = 0;  // |edge|
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (G[i][j]) ++deg[i], ++deg[j], ++M;
        }
    }
    vector<bool> used(n);

    int lim = sqrt(2*M);

    while (true) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] and deg[i] < lim) {
                u = i;
                used[u] = true;
                break;
            }
        }

        vector<int> neighbor;
        if (u != -1) neighbor.push_back(u);
        for (int v = 0; v < n; ++v) if (!used[v]) {
            if (u == -1 or G[u][v]) {
                neighbor.push_back(v);
            }
        }

        int sz = neighbor.size();
        vector<int> bit(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (G[neighbor[i]][neighbor[j]]) {
                    bit[i] |= 1 << j;
                }
            }
        }

        vector<bool> dp(1<<sz);
        dp[0] = true;
        for (int s = 1; s < 1<<sz; ++s) {
            int i = __builtin_ffs(s) - 1;
            dp[s] = dp[s & ~(1<<i)] and (~bit[i] & s) == 0;
            if (dp[s]) {
                vector<int> vs;
                for (int i = 0; i < sz; ++i) if (s >> i & 1) {
                    vs.push_back(neighbor[i]);
                }
                ret = max(ret, f(vs));
            }
        }

        if (u == -1) break;

        for (int v : neighbor) {
            --deg[v], --deg[u];
            G[u][v] = G[v][u] = false;
        }
    }

    return ret;
}

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

#line 2 "lib/graph/maximum_clique.cpp"

template<typename T>
T maximum_clique(
        vector<vector<bool>> G,
        const function<T(const vector<int>&)>& f) {

    // O(2^sqrt(2M) N) ?

    // G: undirected graph (matrix)
    // f: return max(f(clique set))

    T ret = numeric_limits<T>::min();

    int n = G.size();
    vector<int> deg(n);
    int M = 0;  // |edge|
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (G[i][j]) ++deg[i], ++deg[j], ++M;
        }
    }
    vector<bool> used(n);

    int lim = sqrt(2*M);

    while (true) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] and deg[i] < lim) {
                u = i;
                used[u] = true;
                break;
            }
        }

        vector<int> neighbor;
        if (u != -1) neighbor.push_back(u);
        for (int v = 0; v < n; ++v) if (!used[v]) {
            if (u == -1 or G[u][v]) {
                neighbor.push_back(v);
            }
        }

        int sz = neighbor.size();
        vector<int> bit(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (G[neighbor[i]][neighbor[j]]) {
                    bit[i] |= 1 << j;
                }
            }
        }

        vector<bool> dp(1<<sz);
        dp[0] = true;
        for (int s = 1; s < 1<<sz; ++s) {
            int i = __builtin_ffs(s) - 1;
            dp[s] = dp[s & ~(1<<i)] and (~bit[i] & s) == 0;
            if (dp[s]) {
                vector<int> vs;
                for (int i = 0; i < sz; ++i) if (s >> i & 1) {
                    vs.push_back(neighbor[i]);
                }
                ret = max(ret, f(vs));
            }
        }

        if (u == -1) break;

        for (int v : neighbor) {
            --deg[v], --deg[u];
            G[u][v] = G[v][u] = false;
        }
    }

    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

