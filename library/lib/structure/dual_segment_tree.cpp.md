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


# :heavy_check_mark: lib/structure/dual_segment_tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/dual_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/structure/dual_segment_tree/ruq.test.cpp.html">test/structure/dual_segment_tree/ruq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename OM>
struct DualSegmentTree {
    int n, sz;
    vector<OM> lazy;
    const function<OM(OM,OM)> h;
    const OM oe;
    // h: 作用素をマージする関数
    // oe: 作用素の単位元

    DualSegmentTree(
            int n,
            const function<OM(OM,OM)>& h,
            const OM& oe
            ) : n(n), h(h), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        lazy.assign(2*sz, oe);
    }

    void set(int i, const OM& x) {
        lazy.at(i + sz) = x;
    }

    OM merge(const OM& a, const OM& b) const {
        if (a == oe) return b;
        if (b == oe) return a;
        return h(a, b);
    }

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = merge(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = merge(lazy[2*k+1], lazy[k]);
            lazy[k] = oe;
        }
    }

    void _update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = merge(lazy[k], x);
            propagate(k, r - l);
        } else {
            _update(a, b, x, 2*k,   l, (l+r)/2);
            _update(a, b, x, 2*k+1, (l+r)/2, r);
        }
    }

    void update(int a, int b, const OM& x) {
        // update [a, b) with x.
        _update(a, b, x, 1, 0, sz);
    }

    OM _query(int i, int k, int l, int r) {
        if (l+1 == r) return lazy[l + sz];
        propagate(k, r - l);
        int m = (l+r)/2;
        if (i < m) return _query(i, 2*k,   l, m);
        else       return _query(i, 2*k+1, m, r);
    }

    OM operator[](int i) {
        return _query(i, 1, 0, sz);
    }

    friend ostream& operator<<(ostream& os, DualSegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
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


#line 2 "lib/structure/dual_segment_tree.cpp"

template<typename OM>
struct DualSegmentTree {
    int n, sz;
    vector<OM> lazy;
    const function<OM(OM,OM)> h;
    const OM oe;
    // h: 作用素をマージする関数
    // oe: 作用素の単位元

    DualSegmentTree(
            int n,
            const function<OM(OM,OM)>& h,
            const OM& oe
            ) : n(n), h(h), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        lazy.assign(2*sz, oe);
    }

    void set(int i, const OM& x) {
        lazy.at(i + sz) = x;
    }

    OM merge(const OM& a, const OM& b) const {
        if (a == oe) return b;
        if (b == oe) return a;
        return h(a, b);
    }

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = merge(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = merge(lazy[2*k+1], lazy[k]);
            lazy[k] = oe;
        }
    }

    void _update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = merge(lazy[k], x);
            propagate(k, r - l);
        } else {
            _update(a, b, x, 2*k,   l, (l+r)/2);
            _update(a, b, x, 2*k+1, (l+r)/2, r);
        }
    }

    void update(int a, int b, const OM& x) {
        // update [a, b) with x.
        _update(a, b, x, 1, 0, sz);
    }

    OM _query(int i, int k, int l, int r) {
        if (l+1 == r) return lazy[l + sz];
        propagate(k, r - l);
        int m = (l+r)/2;
        if (i < m) return _query(i, 2*k,   l, m);
        else       return _query(i, 2*k+1, m, r);
    }

    OM operator[](int i) {
        return _query(i, 1, 0, sz);
    }

    friend ostream& operator<<(ostream& os, DualSegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

