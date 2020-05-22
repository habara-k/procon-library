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


# :heavy_check_mark: test/number/bell/bell.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a5ce40af8caf9ecb21752e52fc5b624f">test/number/bell</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/bell/bell.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-22 14:51:11+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/number/bell.cpp.html">lib/number/bell.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/number/combination.cpp.html">lib/number/combination.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/number/modint.cpp.html">lib/number/modint.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/number/stirling.cpp.html">lib/number/stirling.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/bell.cpp"

int main() {
    int64_t n, k; cin >> n >> k;

    using Int = modint<MOD>;

    cout << Bell<Int>(n, k) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/bell/bell.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"

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
    using LL = int64_t;
    LL x;

public:
    modint(LL x=0) : x(x < 0 ? ((x % mod) + mod) % mod : x % mod) {}

    const modint operator-() const { return (-x + mod) % mod; }

    modint& operator+=(const modint& rhs) {
        (x += rhs.x) %= mod;
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
        return *this *= rhs.pow(mod-2);
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

    const modint pow(LL n) const {
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
        return lhs.x != rhs.x;
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.x;
    }

    friend istream& operator>>(istream& is, modint& a) {
        LL tmp; is >> tmp; a = tmp;
        return is;
    }
};
#line 1 "lib/number/combination.cpp"


#line 4 "lib/number/combination.cpp"

template<typename Field>
struct Combination {
    vector<Field> _fact, _rfact, _inv;

    Combination(int n) : _fact(n), _rfact(n), _inv(n) {
        _fact[0] = _rfact[n-1] = 1;
        for (int i = 1; i < n; ++i) _fact[i] = _fact[i-1] * i;
        _rfact[n-1] /= _fact[n-1];
        for (int i = n-1; i > 0; --i) _rfact[i-1] = _rfact[i] * i;
        for (int i = 1; i < n; ++i) _inv[i] = _rfact[i] * _fact[i-1];
    }

    inline Field fact(int k) const { return _fact.at(k); }

    inline Field rfact(int k) const { return _rfact.at(k); }

    inline Field inv(int k) const { assert(k != 0); return _inv.at(k); }

    Field P(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(n-r);
    }

    Field C(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n-r);
    }

    Field H (int n, int r) const {
        return (n == 0 and r == 0) ? 1 : C(n+r-1, r);
    }
};

#line 3 "lib/number/stirling.cpp"

// スターリング数
// Stirling(n, k) := 区別できるn 個のボールを
//                   区別できないk 個の箱に入れる場合の数
//                   (ただし空箱はNG)
template<typename Field>
Field Stirling(int64_t n, int k) {
    Combination<Field> comb(k+1);

    Field ret = 0;
    for (int i = 0; i <= k; ++i) {
        ret += comb.C(k, i) * Field{k-i}.pow(n) * (i & 1 ? -1 : 1);
    }
    return ret /= comb.fact(k);
}
#line 3 "lib/number/bell.cpp"

// Bell 数
// Bell(n, k) := 区別できるn 個のボールを,
//               区別できないk 個の箱に入れる場合の数
template<typename Field>
Field Bell(int64_t n, int k) {
    Field ret = 0;
    for (int i = 0; i <= k; ++i) {
        ret += Stirling<Field>(n, i);
    }
    return ret;
}
#line 5 "test/number/bell/bell.test.cpp"

int main() {
    int64_t n, k; cin >> n >> k;

    using Int = modint<MOD>;

    cout << Bell<Int>(n, k) << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

