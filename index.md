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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# {{ site.title }}

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions)
<a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

{% if site.github.project_tagline %}{{ site.github.project_tagline }}{% else %}This documentation is automatically generated by <a href="https://github.com/kmyk/online-judge-verify-helper">online-judge-verify-helper</a>.{% endif %}

## Library Files

<div id="e8acc63b1e238f3255c900eed37254b8"></div>

### lib

* :heavy_check_mark: <a href="library/lib/template.cpp.html">lib/template.cpp</a>


<div id="77c6183086c03e38260b57f4d8fbb66c"></div>

### lib/algorithm

* :heavy_check_mark: <a href="library/lib/algorithm/inversion.cpp.html">lib/algorithm/inversion.cpp</a>
* :heavy_check_mark: <a href="library/lib/algorithm/longest_increasing_subsequence.cpp.html">lib/algorithm/longest_increasing_subsequence.cpp</a>


<div id="7096d029078708cdbb96f2303d66dee8"></div>

### lib/geometry

* :heavy_check_mark: <a href="library/lib/geometry/2D_template.cpp.html">lib/geometry/2D_template.cpp</a>
* :warning: <a href="library/lib/geometry/3D_template.cpp.html">lib/geometry/3D_template.cpp</a>
* :heavy_check_mark: <a href="library/lib/geometry/polygon.cpp.html">lib/geometry/polygon.cpp</a>


<div id="6e267a37887a7dcb68cbf7008d6c7e48"></div>

### lib/graph

* :heavy_check_mark: <a href="library/lib/graph/dijkstra.cpp.html">lib/graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/dinic.cpp.html">lib/graph/dinic.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/euler_tour.cpp.html">lib/graph/euler_tour.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/ford_fulkerson.cpp.html">lib/graph/ford_fulkerson.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/heavy_light_decomposition.cpp.html">lib/graph/heavy_light_decomposition.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/kruskal.cpp.html">lib/graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/lowest_common_ancestor.cpp.html">lib/graph/lowest_common_ancestor.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/maximum_clique.cpp.html">lib/graph/maximum_clique.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/primal_dual.cpp.html">lib/graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/re_rooting.cpp.html">lib/graph/re_rooting.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/strongly_connected_components.cpp.html">lib/graph/strongly_connected_components.cpp</a>
* :warning: <a href="library/lib/graph/topological_sort.cpp.html">lib/graph/topological_sort.cpp</a>
* :warning: <a href="library/lib/graph/two_edge_connected_components.cpp.html">lib/graph/two_edge_connected_components.cpp</a>
* :heavy_check_mark: <a href="library/lib/graph/warshall_floyd.cpp.html">lib/graph/warshall_floyd.cpp</a>


<div id="12cd94d703d26487f7477e7dcce25e7f"></div>

### lib/number

* :heavy_check_mark: <a href="library/lib/number/bell.cpp.html">lib/number/bell.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/combination.cpp.html">lib/number/combination.cpp</a>
* :warning: <a href="library/lib/number/euler_phi.cpp.html">lib/number/euler_phi.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/extended_gcd.cpp.html">lib/number/extended_gcd.cpp</a>
* :warning: <a href="library/lib/number/fast_mobius_transform.cpp.html">lib/number/fast_mobius_transform.cpp</a>
* :warning: <a href="library/lib/number/fast_zeta_transform.cpp.html">lib/number/fast_zeta_transform.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/is_prime.cpp.html">lib/number/is_prime.cpp</a>
* :warning: <a href="library/lib/number/matrix.cpp.html">lib/number/matrix.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/modint.cpp.html">lib/number/modint.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/partition.cpp.html">lib/number/partition.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/prime_factorize.cpp.html">lib/number/prime_factorize.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/prime_table.cpp.html">lib/number/prime_table.cpp</a>
* :heavy_check_mark: <a href="library/lib/number/stirling.cpp.html">lib/number/stirling.cpp</a>


<div id="2fde05eafc6645110721cf5a4d8688d4"></div>

### lib/other

* :heavy_check_mark: <a href="library/lib/other/dice.cpp.html">lib/other/dice.cpp</a>


<div id="9a48db5fb6f746df590a3d4604f6478b"></div>

### lib/string

* :heavy_check_mark: <a href="library/lib/string/rolling_hash.cpp.html">lib/string/rolling_hash.cpp</a>


<div id="c4d905b3311a5371af1ce28a5d3ead13"></div>

### lib/structure

* :heavy_check_mark: <a href="library/lib/structure/binary_indexed_tree.cpp.html">lib/structure/binary_indexed_tree.cpp</a>
* :heavy_check_mark: <a href="library/lib/structure/lazy_segment_tree.cpp.html">lib/structure/lazy_segment_tree.cpp</a>
* :heavy_check_mark: <a href="library/lib/structure/persistent_segment_tree.cpp.html">lib/structure/persistent_segment_tree.cpp</a>
* :heavy_check_mark: <a href="library/lib/structure/randomized_binary_search_tree.cpp.html">lib/structure/randomized_binary_search_tree.cpp</a>
* :heavy_check_mark: <a href="library/lib/structure/segment_tree.cpp.html">lib/structure/segment_tree.cpp</a>
* :heavy_check_mark: <a href="library/lib/structure/union_find.cpp.html">lib/structure/union_find.cpp</a>
* :heavy_check_mark: <a href="library/lib/structure/weighted_union_find.cpp.html">lib/structure/weighted_union_find.cpp</a>


<div id="1e45766cad4fc615f4b62c4dd8d0991f"></div>

### vim/src

* :warning: <a href="library/vim/src/base-template.cpp.html">vim/src/base-template.cpp</a>


<div id="0228fcaedf4e606a4784400ed59fd6ef"></div>

### vim/template/cpp

* :warning: <a href="library/vim/template/cpp/base-main.cpp.html">vim/template/cpp/base-main.cpp</a>


## Verify Files

* :heavy_check_mark: <a href="verify/test/algorithm/inversion/inversion.test.cpp.html">test/algorithm/inversion/inversion.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/algorithm/longest_increasing_subsequence/longest_increasing_subsequence.test.cpp.html">test/algorithm/longest_increasing_subsequence/longest_increasing_subsequence.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/2D_template/counter_clockwise.test.cpp.html">test/geometry/2D_template/counter_clockwise.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/2D_template/crosspoint.test.cpp.html">test/geometry/2D_template/crosspoint.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/2D_template/distance.test.cpp.html">test/geometry/2D_template/distance.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/2D_template/intersection.test.cpp.html">test/geometry/2D_template/intersection.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/2D_template/parallel_orthogonal.test.cpp.html">test/geometry/2D_template/parallel_orthogonal.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/2D_template/projection.test.cpp.html">test/geometry/2D_template/projection.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/polygon/area.test.cpp.html">test/geometry/polygon/area.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/polygon/contains.test.cpp.html">test/geometry/polygon/contains.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/polygon/convex_cut.test.cpp.html">test/geometry/polygon/convex_cut.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/polygon/convex_hull.test.cpp.html">test/geometry/polygon/convex_hull.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/polygon/diameter.test.cpp.html">test/geometry/polygon/diameter.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/geometry/polygon/is_convex.test.cpp.html">test/geometry/polygon/is_convex.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/dijkstra/dijkstra.test.cpp.html">test/graph/dijkstra/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/dinic/dinic.test.cpp.html">test/graph/dinic/dinic.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/euler_tour/euler_tour.test.cpp.html">test/graph/euler_tour/euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/ford_fulkerson/ford_fulkerson.test.cpp.html">test/graph/ford_fulkerson/ford_fulkerson.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp.html">test/graph/heavy_light_decomposition/heavy_light_decomposition.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/heavy_light_decomposition/lca.test.cpp.html">test/graph/heavy_light_decomposition/lca.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/kruskal/kruskal.test.cpp.html">test/graph/kruskal/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp.html">test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/lowlink/articulation.test.cpp.html">test/graph/lowlink/articulation.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/lowlink/bridge.test.cpp.html">test/graph/lowlink/bridge.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/maximum_clique/maximum_clique.test.cpp.html">test/graph/maximum_clique/maximum_clique.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/primal_dual/primal_dual.test.cpp.html">test/graph/primal_dual/primal_dual.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/re_rooting/re_rooting.test.cpp.html">test/graph/re_rooting/re_rooting.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/strongly_connected_components/strongly_connected_components.test.cpp.html">test/graph/strongly_connected_components/strongly_connected_components.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/graph/warshall_floyd/warshall_floyd.test.cpp.html">test/graph/warshall_floyd/warshall_floyd.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/bell/bell.test.cpp.html">test/number/bell/bell.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/combination/combination.test.cpp.html">test/number/combination/combination.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/extended_gcd/extended_gcd.test.cpp.html">test/number/extended_gcd/extended_gcd.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/is_prime/is_prime.test.cpp.html">test/number/is_prime/is_prime.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/modint/modint.test.cpp.html">test/number/modint/modint.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/partition/partition1.test.cpp.html">test/number/partition/partition1.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/partition/partition2.test.cpp.html">test/number/partition/partition2.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/prime_factorize/prime_factorize.test.cpp.html">test/number/prime_factorize/prime_factorize.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/prime_table/prime_table.test.cpp.html">test/number/prime_table/prime_table.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/number/stirling/stirling.test.cpp.html">test/number/stirling/stirling.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/other/dice/dice.test.cpp.html">test/other/dice/dice.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/string/rolling_hash/rolling_hash.test.cpp.html">test/string/rolling_hash/rolling_hash.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/binary_indexed_tree/raq.test.cpp.html">test/structure/binary_indexed_tree/raq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/binary_indexed_tree/rsq.test.cpp.html">test/structure/binary_indexed_tree/rsq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/lazy_segment_tree/rmq_raq.test.cpp.html">test/structure/lazy_segment_tree/rmq_raq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/lazy_segment_tree/rmq_ruq.test.cpp.html">test/structure/lazy_segment_tree/rmq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/lazy_segment_tree/rsq_raq.test.cpp.html">test/structure/lazy_segment_tree/rsq_raq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/lazy_segment_tree/rsq_ruq.test.cpp.html">test/structure/lazy_segment_tree/rsq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/lazy_segment_tree/ruq.test.cpp.html">test/structure/lazy_segment_tree/ruq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp.html">test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/randomized_binary_search_tree/rmq_raq.test.cpp.html">test/structure/randomized_binary_search_tree/rmq_raq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/randomized_binary_search_tree/rmq_ruq.test.cpp.html">test/structure/randomized_binary_search_tree/rmq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/randomized_binary_search_tree/rsq_raq.test.cpp.html">test/structure/randomized_binary_search_tree/rsq_raq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/randomized_binary_search_tree/rsq_ruq.test.cpp.html">test/structure/randomized_binary_search_tree/rsq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/randomized_binary_search_tree/ruq.test.cpp.html">test/structure/randomized_binary_search_tree/ruq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/segment_tree/rmq.test.cpp.html">test/structure/segment_tree/rmq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/segment_tree/rsq.test.cpp.html">test/structure/segment_tree/rsq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/union_find/union_find.test.cpp.html">test/structure/union_find/union_find.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/structure/weighted_union_find/weighted_union_find.test.cpp.html">test/structure/weighted_union_find/weighted_union_find.test.cpp</a>

