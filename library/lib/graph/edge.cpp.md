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


# :heavy_check_mark: lib/graph/edge.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/edge.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 20:05:03+09:00




## Required by

* :heavy_check_mark: <a href="dijkstra.cpp.html">lib/graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="kruskal.cpp.html">lib/graph/kruskal.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra/dijkstra.test.cpp.html">test/graph/dijkstra/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/kruskal/kruskal.test.cpp.html">test/graph/kruskal/kruskal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef EDGE
#define EDGE

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
#line 1 "lib/graph/edge.cpp"



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

