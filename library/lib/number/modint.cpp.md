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


# :heavy_check_mark: lib/number/modint.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 23:31:52+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/number/bell/bell.test.cpp.html">test/number/bell/bell.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/combination/combination.test.cpp.html">test/number/combination/combination.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/modint/modint.test.cpp.html">test/number/modint/modint.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/partition/partition1.test.cpp.html">test/number/partition/partition1.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/partition/partition2.test.cpp.html">test/number/partition/partition2.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/stirling/stirling.test.cpp.html">test/number/stirling/stirling.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<int64_t mod>
class modint {
    int64_t x;

public:
    modint(int64_t x = 0) : x(x < 0 ? ((x % mod) + mod) % mod : x % mod) {}

    const modint operator-() const { return x ? mod - x : 0; }

    modint& operator+=(const modint& rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        (x *= rhs.x) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        return *this *= rhs.pow(mod - 2);
    }

    friend const modint operator+(modint lhs, const modint& rhs) {
        return lhs += rhs;
    }
    friend const modint operator-(modint lhs, const modint& rhs) {
        return lhs -= rhs;
    }
    friend const modint operator*(modint lhs, const modint& rhs) {
        return lhs *= rhs;
    }
    friend const modint operator/(modint lhs, const modint& rhs) {
        return lhs /= rhs;
    }

    const modint pow(int64_t n) const {
        modint ret = 1, tmp = *this;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp; n >>= 1;
        }
        return ret;
    }

    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(const modint& lhs, const modint& rhs) {
        return !(lhs == rhs);
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.x;
    }
    friend istream& operator>>(istream& is, modint& a) {
        int64_t tmp; is >> tmp; a = tmp;
        return is;
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


#line 2 "lib/number/modint.cpp"

template<int64_t mod>
class modint {
    int64_t x;

public:
    modint(int64_t x = 0) : x(x < 0 ? ((x % mod) + mod) % mod : x % mod) {}

    const modint operator-() const { return x ? mod - x : 0; }

    modint& operator+=(const modint& rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        (x *= rhs.x) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        return *this *= rhs.pow(mod - 2);
    }

    friend const modint operator+(modint lhs, const modint& rhs) {
        return lhs += rhs;
    }
    friend const modint operator-(modint lhs, const modint& rhs) {
        return lhs -= rhs;
    }
    friend const modint operator*(modint lhs, const modint& rhs) {
        return lhs *= rhs;
    }
    friend const modint operator/(modint lhs, const modint& rhs) {
        return lhs /= rhs;
    }

    const modint pow(int64_t n) const {
        modint ret = 1, tmp = *this;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp; n >>= 1;
        }
        return ret;
    }

    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(const modint& lhs, const modint& rhs) {
        return !(lhs == rhs);
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.x;
    }
    friend istream& operator>>(istream& is, modint& a) {
        int64_t tmp; is >> tmp; a = tmp;
        return is;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

