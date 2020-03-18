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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: lib/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-18 20:03:32+09:00




## Required by

* :heavy_check_mark: <a href="algorithm/inversion.cpp.html">lib/algorithm/inversion.cpp</a>
* :heavy_check_mark: <a href="algorithm/longest_increasing_subsequence.cpp.html">lib/algorithm/longest_increasing_subsequence.cpp</a>
* :heavy_check_mark: <a href="graph/dijkstra.cpp.html">lib/graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="graph/dinic.cpp.html">lib/graph/dinic.cpp</a>
* :heavy_check_mark: <a href="graph/kruskal.cpp.html">lib/graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="graph/lowest_common_ancestor.cpp.html">lib/graph/lowest_common_ancestor.cpp</a>
* :heavy_check_mark: <a href="graph/strongly_connected_components.cpp.html">lib/graph/strongly_connected_components.cpp</a>
* :heavy_check_mark: <a href="graph/warshall_floyd.cpp.html">lib/graph/warshall_floyd.cpp</a>
* :heavy_check_mark: <a href="number/bell.cpp.html">lib/number/bell.cpp</a>
* :heavy_check_mark: <a href="number/combination.cpp.html">lib/number/combination.cpp</a>
* :heavy_check_mark: <a href="number/extended_gcd.cpp.html">lib/number/extended_gcd.cpp</a>
* :heavy_check_mark: <a href="number/factorial.cpp.html">lib/number/factorial.cpp</a>
* :heavy_check_mark: <a href="number/is_prime.cpp.html">lib/number/is_prime.cpp</a>
* :heavy_check_mark: <a href="number/modint.cpp.html">lib/number/modint.cpp</a>
* :heavy_check_mark: <a href="number/partition.cpp.html">lib/number/partition.cpp</a>
* :heavy_check_mark: <a href="number/prime_factorize.cpp.html">lib/number/prime_factorize.cpp</a>
* :heavy_check_mark: <a href="number/prime_table.cpp.html">lib/number/prime_table.cpp</a>
* :heavy_check_mark: <a href="number/stirling.cpp.html">lib/number/stirling.cpp</a>
* :heavy_check_mark: <a href="string/rolling_hash.cpp.html">lib/string/rolling_hash.cpp</a>
* :heavy_check_mark: <a href="structure/binary_indexed_tree.cpp.html">lib/structure/binary_indexed_tree.cpp</a>
* :heavy_check_mark: <a href="structure/lazy_segment_tree.cpp.html">lib/structure/lazy_segment_tree.cpp</a>
* :heavy_check_mark: <a href="structure/segment_tree.cpp.html">lib/structure/segment_tree.cpp</a>
* :heavy_check_mark: <a href="structure/union_find.cpp.html">lib/structure/union_find.cpp</a>
* :heavy_check_mark: <a href="structure/weighted_union_find.cpp.html">lib/structure/weighted_union_find.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/algorithm/inversion/inversion.test.cpp.html">test/algorithm/inversion/inversion.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/algorithm/longest_increasing_subsequence/longest_increasing_subsequence.test.cpp.html">test/algorithm/longest_increasing_subsequence/longest_increasing_subsequence.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dijkstra/dijkstra.test.cpp.html">test/graph/dijkstra/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dinic/dinic.test.cpp.html">test/graph/dinic/dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/kruskal/kruskal.test.cpp.html">test/graph/kruskal/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp.html">test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/strongly_connected_components/strongly_connected_components.test.cpp.html">test/graph/strongly_connected_components/strongly_connected_components.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/warshall_floyd/warshall_floyd.test.cpp.html">test/graph/warshall_floyd/warshall_floyd.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/bell/bell.test.cpp.html">test/number/bell/bell.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/combination/combination.test.cpp.html">test/number/combination/combination.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/extended_gcd/extended_gcd.test.cpp.html">test/number/extended_gcd/extended_gcd.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/factorial/factorial.test.cpp.html">test/number/factorial/factorial.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/is_prime/is_prime.test.cpp.html">test/number/is_prime/is_prime.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/modint/modint.test.cpp.html">test/number/modint/modint.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/partition/partition1.test.cpp.html">test/number/partition/partition1.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/partition/partition2.test.cpp.html">test/number/partition/partition2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/prime_factorize/prime_factorize.test.cpp.html">test/number/prime_factorize/prime_factorize.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/prime_table/prime_table.test.cpp.html">test/number/prime_table/prime_table.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/stirling/stirling.test.cpp.html">test/number/stirling/stirling.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/string/rolling_hash/rolling_hash.test.cpp.html">test/string/rolling_hash/rolling_hash.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/binary_indexed_tree/raq.test.cpp.html">test/structure/binary_indexed_tree/raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/binary_indexed_tree/rsq.test.cpp.html">test/structure/binary_indexed_tree/rsq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rmq_raq.test.cpp.html">test/structure/lazy_segment_tree/rmq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rmq_ruq.test.cpp.html">test/structure/lazy_segment_tree/rmq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rsq_raq.test.cpp.html">test/structure/lazy_segment_tree/rsq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rsq_ruq.test.cpp.html">test/structure/lazy_segment_tree/rsq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/ruq.test.cpp.html">test/structure/lazy_segment_tree/ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/segment_tree/rmq.test.cpp.html">test/structure/segment_tree/rmq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/union_find/union_find.test.cpp.html">test/structure/union_find/union_find.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/weighted_union_find/weighted_union_find.test.cpp.html">test/structure/weighted_union_find/weighted_union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef TEMPLATE
#define TEMPLATE
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
#endif

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


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

