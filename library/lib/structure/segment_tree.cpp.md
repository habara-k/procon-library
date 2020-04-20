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


# :heavy_check_mark: lib/structure/segment_tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/structure/segment_tree/rmq.test.cpp.html">test/structure/segment_tree/rmq.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/structure/segment_tree/rsq.test.cpp.html">test/structure/segment_tree/rsq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename M>
struct SegmentTree {
    int n, sz;
    vector<M> data;
    const function<M(M,M)> f;
    const M e;

    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e
            ) : n(n), f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
    }

    void build(const vector<M>& v) {
        assert(v.size() <= n);
        for (int i = 0; i < v.size(); ++i) {
            data[i + sz] = v[i];
        }
        for (int i = sz-1; i > 0; --i) {
            data[i] = f(data[2*i], data[2*i+1]);
        }
    }

    template<typename UpdateQuery>
    void update(int k, const UpdateQuery& q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M _query(int a, int b, int k, int l, int r) const {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return data[k];
        return f(_query(a,b,2*k,  l,(l+r)/2),
                 _query(a,b,2*k+1,(l+r)/2,r));
    }

    M query(int a, int b) const {
        // return f[a,b)
        return _query(a, b, 1, 0, sz);
    }

    M operator[](int i) const {
        return data.at(i + sz);
    }

    friend ostream& operator<<(ostream& os, const SegmentTree& s) {
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


#line 2 "lib/structure/segment_tree.cpp"

template<typename M>
struct SegmentTree {
    int n, sz;
    vector<M> data;
    const function<M(M,M)> f;
    const M e;

    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e
            ) : n(n), f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
    }

    void build(const vector<M>& v) {
        assert(v.size() <= n);
        for (int i = 0; i < v.size(); ++i) {
            data[i + sz] = v[i];
        }
        for (int i = sz-1; i > 0; --i) {
            data[i] = f(data[2*i], data[2*i+1]);
        }
    }

    template<typename UpdateQuery>
    void update(int k, const UpdateQuery& q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M _query(int a, int b, int k, int l, int r) const {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return data[k];
        return f(_query(a,b,2*k,  l,(l+r)/2),
                 _query(a,b,2*k+1,(l+r)/2,r));
    }

    M query(int a, int b) const {
        // return f[a,b)
        return _query(a, b, 1, 0, sz);
    }

    M operator[](int i) const {
        return data.at(i + sz);
    }

    friend ostream& operator<<(ostream& os, const SegmentTree& s) {
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

