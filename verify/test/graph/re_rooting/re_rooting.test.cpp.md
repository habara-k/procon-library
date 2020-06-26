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


# :heavy_check_mark: test/graph/re_rooting/re_rooting.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#201475acb17386f13f3e53190e3bcecc">test/graph/re_rooting</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/re_rooting/re_rooting.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 12:56:23+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/edge.cpp.html">lib/graph/edge.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/graph/re_rooting.cpp.html">lib/graph/re_rooting.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "../../../lib/graph/edge.cpp"
#include "../../../lib/graph/re_rooting.cpp"

int main() {
    int n; cin >> n;
    vector<vector<edge<int>>> G(n);

    using P = pair<int,int>;

    ReRooting<int,P> tr(
            n,
            [](P a, P b){
                vector<int> v{a.first,a.second,b.first,b.second};
                sort(v.rbegin(),v.rend());
                return make_pair(v[0],v[1]);
                },
            [](P a, int w){
                return make_pair(a.first+w, 0);
                },
            P{0,0});

    for (int i = 0; i < n-1; ++i) {
        int s, t, w; cin >> s >> t >> w;
        tr.add_edge(s, t, w);
    }

    int ans = 0;
    for (auto& p : tr.solve()) {
        chmax(ans, p.first);
    }

    cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/re_rooting/re_rooting.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#line 1 "lib/graph/edge.cpp"


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


#line 4 "lib/graph/edge.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


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
        for (int i = 0; i < g.size(); ++i) {
            ldp[i].assign(g[i].size()+1, init);
            rdp[i].assign(g[i].size()+1, init);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size()-1;
        }
        vector<T> ret(g.size());
        for (int i = 0; i < g.size(); ++i) {
            ret[i] = dfs(i, -1);
        }
        return ret;
    }
};
#line 5 "test/graph/re_rooting/re_rooting.test.cpp"

int main() {
    int n; cin >> n;
    vector<vector<edge<int>>> G(n);

    using P = pair<int,int>;

    ReRooting<int,P> tr(
            n,
            [](P a, P b){
                vector<int> v{a.first,a.second,b.first,b.second};
                sort(v.rbegin(),v.rend());
                return make_pair(v[0],v[1]);
                },
            [](P a, int w){
                return make_pair(a.first+w, 0);
                },
            P{0,0});

    for (int i = 0; i < n-1; ++i) {
        int s, t, w; cin >> s >> t >> w;
        tr.add_edge(s, t, w);
    }

    int ans = 0;
    for (auto& p : tr.solve()) {
        chmax(ans, p.first);
    }

    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

