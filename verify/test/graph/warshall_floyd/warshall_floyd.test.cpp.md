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


# :heavy_check_mark: test/graph/warshall_floyd/warshall_floyd.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7c505010898c1988cd7f9f1bd5d139cc">test/graph/warshall_floyd</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/warshall_floyd/warshall_floyd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 20:05:03+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/warshall_floyd.cpp.html">lib/graph/warshall_floyd.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../../lib/graph/warshall_floyd.cpp"

int main() {
    int V, E;
    cin >> V >> E;

    const int INF = numeric_limits<int>::max();
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i) G[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
    }

    warshall_floyd(G);
    for (int i = 0; i < V; ++i) {
        if (G[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) putchar(' ');
            if (G[i][j] == INF) printf("INF");
            else printf("%d", G[i][j]);
        }
        putchar('\n');
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/warshall_floyd/warshall_floyd.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

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


#line 2 "lib/graph/warshall_floyd.cpp"

template<typename T>
void warshall_floyd(vector<vector<T>> &g) {
    const auto INF = numeric_limits<T>::max();
    int n = g.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][k] == INF or g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
#line 4 "test/graph/warshall_floyd/warshall_floyd.test.cpp"

int main() {
    int V, E;
    cin >> V >> E;

    const int INF = numeric_limits<int>::max();
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i) G[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
    }

    warshall_floyd(G);
    for (int i = 0; i < V; ++i) {
        if (G[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) putchar(' ');
            if (G[i][j] == INF) printf("INF");
            else printf("%d", G[i][j]);
        }
        putchar('\n');
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

