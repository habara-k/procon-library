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
    - Last commit date: 2020-04-20 18:48:42+09:00




## Required by

* :heavy_check_mark: <a href="algorithm/inversion.cpp.html">lib/algorithm/inversion.cpp</a>
* :heavy_check_mark: <a href="algorithm/longest_increasing_subsequence.cpp.html">lib/algorithm/longest_increasing_subsequence.cpp</a>
* :heavy_check_mark: <a href="geometry/2D_template.cpp.html">lib/geometry/2D_template.cpp</a>
* :warning: <a href="geometry/3D_template.cpp.html">lib/geometry/3D_template.cpp</a>
* :heavy_check_mark: <a href="geometry/polygon.cpp.html">lib/geometry/polygon.cpp</a>
* :heavy_check_mark: <a href="graph/dijkstra.cpp.html">lib/graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="graph/dinic.cpp.html">lib/graph/dinic.cpp</a>
* :heavy_check_mark: <a href="graph/edge.cpp.html">lib/graph/edge.cpp</a>
* :heavy_check_mark: <a href="graph/euler_tour.cpp.html">lib/graph/euler_tour.cpp</a>
* :heavy_check_mark: <a href="graph/ford_fulkerson.cpp.html">lib/graph/ford_fulkerson.cpp</a>
* :heavy_check_mark: <a href="graph/heavy_light_decomposition.cpp.html">lib/graph/heavy_light_decomposition.cpp</a>
* :heavy_check_mark: <a href="graph/kruskal.cpp.html">lib/graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="graph/lowest_common_ancestor.cpp.html">lib/graph/lowest_common_ancestor.cpp</a>
* :heavy_check_mark: <a href="graph/lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="graph/maximum_clique.cpp.html">lib/graph/maximum_clique.cpp</a>
* :heavy_check_mark: <a href="graph/primal_dual.cpp.html">lib/graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="graph/re_rooting.cpp.html">lib/graph/re_rooting.cpp</a>
* :heavy_check_mark: <a href="graph/strongly_connected_components.cpp.html">lib/graph/strongly_connected_components.cpp</a>
* :warning: <a href="graph/topological_sort.cpp.html">lib/graph/topological_sort.cpp</a>
* :warning: <a href="graph/two_edge_connected_components.cpp.html">lib/graph/two_edge_connected_components.cpp</a>
* :heavy_check_mark: <a href="graph/warshall_floyd.cpp.html">lib/graph/warshall_floyd.cpp</a>
* :heavy_check_mark: <a href="number/bell.cpp.html">lib/number/bell.cpp</a>
* :heavy_check_mark: <a href="number/combination.cpp.html">lib/number/combination.cpp</a>
* :warning: <a href="number/euler_phi.cpp.html">lib/number/euler_phi.cpp</a>
* :heavy_check_mark: <a href="number/extended_gcd.cpp.html">lib/number/extended_gcd.cpp</a>
* :warning: <a href="number/fast_mobius_transform.cpp.html">lib/number/fast_mobius_transform.cpp</a>
* :warning: <a href="number/fast_zeta_transform.cpp.html">lib/number/fast_zeta_transform.cpp</a>
* :heavy_check_mark: <a href="number/is_prime.cpp.html">lib/number/is_prime.cpp</a>
* :warning: <a href="number/matrix.cpp.html">lib/number/matrix.cpp</a>
* :heavy_check_mark: <a href="number/modint.cpp.html">lib/number/modint.cpp</a>
* :heavy_check_mark: <a href="number/partition.cpp.html">lib/number/partition.cpp</a>
* :heavy_check_mark: <a href="number/permutation.cpp.html">lib/number/permutation.cpp</a>
* :heavy_check_mark: <a href="number/prime_factorize.cpp.html">lib/number/prime_factorize.cpp</a>
* :heavy_check_mark: <a href="number/prime_table.cpp.html">lib/number/prime_table.cpp</a>
* :heavy_check_mark: <a href="number/stirling.cpp.html">lib/number/stirling.cpp</a>
* :heavy_check_mark: <a href="other/dice.cpp.html">lib/other/dice.cpp</a>
* :heavy_check_mark: <a href="parse/expression.cpp.html">lib/parse/expression.cpp</a>
* :heavy_check_mark: <a href="parse/parser.cpp.html">lib/parse/parser.cpp</a>
* :heavy_check_mark: <a href="string/aho_corasick.cpp.html">lib/string/aho_corasick.cpp</a>
* :heavy_check_mark: <a href="string/rolling_hash.cpp.html">lib/string/rolling_hash.cpp</a>
* :heavy_check_mark: <a href="string/trie.cpp.html">lib/string/trie.cpp</a>
* :heavy_check_mark: <a href="structure/binary_indexed_tree.cpp.html">lib/structure/binary_indexed_tree.cpp</a>
* :heavy_check_mark: <a href="structure/dual_segment_tree.cpp.html">lib/structure/dual_segment_tree.cpp</a>
* :heavy_check_mark: <a href="structure/lazy_randomized_binary_search_tree.cpp.html">lib/structure/lazy_randomized_binary_search_tree.cpp</a>
* :heavy_check_mark: <a href="structure/lazy_segment_tree.cpp.html">lib/structure/lazy_segment_tree.cpp</a>
* :heavy_check_mark: <a href="structure/persistent_segment_tree.cpp.html">lib/structure/persistent_segment_tree.cpp</a>
* :heavy_check_mark: <a href="structure/segment_tree.cpp.html">lib/structure/segment_tree.cpp</a>
* :heavy_check_mark: <a href="structure/union_find.cpp.html">lib/structure/union_find.cpp</a>
* :heavy_check_mark: <a href="structure/weighted_union_find.cpp.html">lib/structure/weighted_union_find.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/algorithm/inversion/inversion.test.cpp.html">test/algorithm/inversion/inversion.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/algorithm/longest_increasing_subsequence/longest_increasing_subsequence.test.cpp.html">test/algorithm/longest_increasing_subsequence/longest_increasing_subsequence.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/counter_clockwise.test.cpp.html">test/geometry/2D_template/counter_clockwise.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/crosspoint.test.cpp.html">test/geometry/2D_template/crosspoint.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/distance.test.cpp.html">test/geometry/2D_template/distance.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/intersection.test.cpp.html">test/geometry/2D_template/intersection.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/parallel_orthogonal.test.cpp.html">test/geometry/2D_template/parallel_orthogonal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/2D_template/projection.test.cpp.html">test/geometry/2D_template/projection.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/area.test.cpp.html">test/geometry/polygon/area.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/contains.test.cpp.html">test/geometry/polygon/contains.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/convex_cut.test.cpp.html">test/geometry/polygon/convex_cut.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/convex_hull.test.cpp.html">test/geometry/polygon/convex_hull.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/diameter.test.cpp.html">test/geometry/polygon/diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/polygon/is_convex.test.cpp.html">test/geometry/polygon/is_convex.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dijkstra/dijkstra.test.cpp.html">test/graph/dijkstra/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dinic/dinic.test.cpp.html">test/graph/dinic/dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/euler_tour/euler_tour.test.cpp.html">test/graph/euler_tour/euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/ford_fulkerson/ford_fulkerson.test.cpp.html">test/graph/ford_fulkerson/ford_fulkerson.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp.html">test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/heavy_light_decomposition/lca.test.cpp.html">test/graph/heavy_light_decomposition/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/kruskal/kruskal.test.cpp.html">test/graph/kruskal/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp.html">test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/lowlink/articulation.test.cpp.html">test/graph/lowlink/articulation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/lowlink/bridge.test.cpp.html">test/graph/lowlink/bridge.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/maximum_clique/maximum_clique.test.cpp.html">test/graph/maximum_clique/maximum_clique.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/primal_dual/primal_dual.test.cpp.html">test/graph/primal_dual/primal_dual.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/re_rooting/re_rooting.test.cpp.html">test/graph/re_rooting/re_rooting.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/strongly_connected_components/strongly_connected_components.test.cpp.html">test/graph/strongly_connected_components/strongly_connected_components.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/warshall_floyd/warshall_floyd.test.cpp.html">test/graph/warshall_floyd/warshall_floyd.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/bell/bell.test.cpp.html">test/number/bell/bell.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/combination/combination.test.cpp.html">test/number/combination/combination.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/extended_gcd/extended_gcd.test.cpp.html">test/number/extended_gcd/extended_gcd.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/is_prime/is_prime.test.cpp.html">test/number/is_prime/is_prime.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/modint/modint.test.cpp.html">test/number/modint/modint.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/partition/partition1.test.cpp.html">test/number/partition/partition1.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/partition/partition2.test.cpp.html">test/number/partition/partition2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/permutation/permutation.test.cpp.html">test/number/permutation/permutation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/prime_factorize/prime_factorize.test.cpp.html">test/number/prime_factorize/prime_factorize.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/prime_table/prime_table.test.cpp.html">test/number/prime_table/prime_table.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/number/stirling/stirling.test.cpp.html">test/number/stirling/stirling.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/other/dice/dice.test.cpp.html">test/other/dice/dice.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/parse/expression/expression.test.cpp.html">test/parse/expression/expression.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/string/aho_corasick/aho_corasick.test.cpp.html">test/string/aho_corasick/aho_corasick.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/string/rolling_hash/rolling_hash.test.cpp.html">test/string/rolling_hash/rolling_hash.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/binary_indexed_tree/raq.test.cpp.html">test/structure/binary_indexed_tree/raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/binary_indexed_tree/rsq.test.cpp.html">test/structure/binary_indexed_tree/rsq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/dual_segment_tree/ruq.test.cpp.html">test/structure/dual_segment_tree/ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_randomized_binary_search_tree/rmq_raq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rmq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_randomized_binary_search_tree/rmq_ruq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rmq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_randomized_binary_search_tree/rsq_raq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rsq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_randomized_binary_search_tree/ruq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rmq_raq.test.cpp.html">test/structure/lazy_segment_tree/rmq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rmq_ruq.test.cpp.html">test/structure/lazy_segment_tree/rmq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rsq_raq.test.cpp.html">test/structure/lazy_segment_tree/rsq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/lazy_segment_tree/rsq_ruq.test.cpp.html">test/structure/lazy_segment_tree/rsq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp.html">test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/segment_tree/rmq.test.cpp.html">test/structure/segment_tree/rmq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/structure/segment_tree/rsq.test.cpp.html">test/structure/segment_tree/rsq.test.cpp</a>
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

#endif

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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

