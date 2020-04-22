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


# :heavy_check_mark: test/graph/strongly_connected_components/strongly_connected_components.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#86cae120d42a0d43d0c5d09d870524dd">test/graph/strongly_connected_components</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/strongly_connected_components/strongly_connected_components.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 20:05:03+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/strongly_connected_components.cpp.html">lib/graph/strongly_connected_components.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../../../lib/graph/strongly_connected_components.cpp"

int main() {
    int V, E, Q;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }

    StronglyConnectedComponents scc(G);
    scc.build();

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << (scc.comp[a] == scc.comp[b] ? "1" : "0") << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/strongly_connected_components/strongly_connected_components.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

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


#line 2 "lib/graph/strongly_connected_components.cpp"

struct StronglyConnectedComponents {
    vector<vector<int>> g, rg, t;
    vector<int> comp, ord, used;

    StronglyConnectedComponents(const vector<vector<int>>& g) :
        g(g), rg(g.size()), comp(g.size(), -1), used(g.size())
    {
        for (int i = 0; i < g.size(); ++i) {
            for (int to : g[i]) {
                rg[to].push_back(i);
            }
        }
    }

    void dfs(int idx) {
        if (used[idx]) return;
        used[idx] = true;
        for (int to : g[idx]) dfs(to);
        ord.push_back(idx);
    }

    void rdfs(int idx, int cnt) {
        if (comp[idx] != -1) return;
        comp[idx] = cnt;
        for (int to : rg[idx]) rdfs(to, cnt);
    }

    void build() {
        for (int i = 0; i < g.size(); ++i) dfs(i);
        reverse(ord.begin(), ord.end());
        int ptr = 0;
        for (int i : ord) if (comp[i] == -1) rdfs(i, ptr), ptr++;

        t.resize(ptr);
        for (int i = 0; i < g.size(); ++i) {
            for (int to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y) continue;
                t[x].push_back(y);
            }
        }
    }
};
#line 4 "test/graph/strongly_connected_components/strongly_connected_components.test.cpp"

int main() {
    int V, E, Q;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }

    StronglyConnectedComponents scc(G);
    scc.build();

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << (scc.comp[a] == scc.comp[b] ? "1" : "0") << endl;
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

