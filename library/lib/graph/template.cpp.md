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


# :heavy_check_mark: lib/graph/template.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Required by

* :heavy_check_mark: <a href="dijkstra.cpp.html">lib/graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="dinic.cpp.html">lib/graph/dinic.cpp</a>
* :heavy_check_mark: <a href="euler_tour.cpp.html">lib/graph/euler_tour.cpp</a>
* :heavy_check_mark: <a href="ford_fulkerson.cpp.html">lib/graph/ford_fulkerson.cpp</a>
* :heavy_check_mark: <a href="heavy_light_decomposition.cpp.html">lib/graph/heavy_light_decomposition.cpp</a>
* :heavy_check_mark: <a href="kruskal.cpp.html">lib/graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="lowest_common_ancestor.cpp.html">lib/graph/lowest_common_ancestor.cpp</a>
* :heavy_check_mark: <a href="lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="maximum_clique.cpp.html">lib/graph/maximum_clique.cpp</a>
* :heavy_check_mark: <a href="primal_dual.cpp.html">lib/graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="re_rooting.cpp.html">lib/graph/re_rooting.cpp</a>
* :heavy_check_mark: <a href="strongly_connected_components.cpp.html">lib/graph/strongly_connected_components.cpp</a>
* :warning: <a href="topological_sort.cpp.html">lib/graph/topological_sort.cpp</a>
* :warning: <a href="two_edge_connected_components.cpp.html">lib/graph/two_edge_connected_components.cpp</a>
* :heavy_check_mark: <a href="warshall_floyd.cpp.html">lib/graph/warshall_floyd.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra/dijkstra.test.cpp.html">test/graph/dijkstra/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/dinic/dinic.test.cpp.html">test/graph/dinic/dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/euler_tour/euler_tour.test.cpp.html">test/graph/euler_tour/euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/ford_fulkerson/ford_fulkerson.test.cpp.html">test/graph/ford_fulkerson/ford_fulkerson.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp.html">test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/heavy_light_decomposition/lca.test.cpp.html">test/graph/heavy_light_decomposition/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/kruskal/kruskal.test.cpp.html">test/graph/kruskal/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp.html">test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/lowlink/articulation.test.cpp.html">test/graph/lowlink/articulation.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/lowlink/bridge.test.cpp.html">test/graph/lowlink/bridge.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/maximum_clique/maximum_clique.test.cpp.html">test/graph/maximum_clique/maximum_clique.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/primal_dual/primal_dual.test.cpp.html">test/graph/primal_dual/primal_dual.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/re_rooting/re_rooting.test.cpp.html">test/graph/re_rooting/re_rooting.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/strongly_connected_components/strongly_connected_components.test.cpp.html">test/graph/strongly_connected_components/strongly_connected_components.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/warshall_floyd/warshall_floyd.test.cpp.html">test/graph/warshall_floyd/warshall_floyd.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp.html">test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef GRAPH_TEMPLATE
#define GRAPH_TEMPLATE
#include "../template.cpp"

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

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

