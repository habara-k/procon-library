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


# :heavy_check_mark: test/number/combination/combination.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#88b7a25864ce5c4f4167b1d8c119c43d">test/number/combination</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/combination/combination.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B</a>


## Depends on

* :question: <a href="../../../../library/lib/number/combination.cpp.html">lib/number/combination.cpp</a>
* :question: <a href="../../../../library/lib/number/modint.cpp.html">lib/number/modint.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/combination.cpp"

int main() {
    int64_t n, k;
    cin >> n >> k;

    if (n > k) {
        cout << 0 << endl;
        return 0;
    }

    using Int = modint<MOD>;
    Combination<Int> comb(k+1);

    cout << comb.C(k, n) * comb.fact(n) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/combination/combination.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

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
struct modint {
    using LL = int64_t;
    LL val;
    modint(LL val=0) : val(((val % mod) + mod) % mod) {}

    const modint operator+() const { return *this; }
    const modint operator-() const { return (-val + mod) % mod; }
    const modint inv() const { return pow(mod-2); }

    modint& operator+=(const modint& rhs) {
        (val += rhs.val) %= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        (val *= rhs.val) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        return *this *= rhs.inv();
    }

    const modint operator+(const modint& rhs) const {
        return modint(*this) += rhs;
    }
    const modint operator-(const modint& rhs) const {
        return modint(*this) -= rhs;
    }
    const modint operator*(const modint& rhs) const {
        return modint(*this) *= rhs;
    }
    const modint operator/(const modint& rhs) const {
        return modint(*this) /= rhs;
    }

    const modint pow(LL n) const {
        modint ret = 1, tmp = val;
        while (n) {
            if (n & 1) ret *= tmp;
            tmp *= tmp; n >>= 1;
        }
        return ret;
    }

    bool operator==(const modint& rhs) const { return val == rhs.val; }
    bool operator!=(const modint& rhs) const { return !(*this == rhs); }

    friend const modint operator+(const LL& lhs, const modint& rhs) {
        return modint(lhs) + rhs;
    }
    friend const modint operator-(const LL& lhs, const modint& rhs) {
        return modint(lhs) - rhs;
    }
    friend const modint operator*(const LL& lhs, const modint& rhs) {
        return modint(lhs) * rhs;
    }
    friend const modint operator/(const LL& lhs, const modint& rhs) {
        return modint(lhs) / rhs;
    }

    friend bool operator==(const LL& lhs, const modint& rhs) {
        return modint(lhs) == rhs;
    }
    friend bool operator!=(const LL& lhs, const modint& rhs) {
        return modint(lhs) != rhs;
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.val;
    }
    friend istream& operator>>(istream& is, modint& a) {
        LL tmp; is >> tmp;
        a = tmp;
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

#line 5 "test/number/combination/combination.test.cpp"

int main() {
    int64_t n, k;
    cin >> n >> k;

    if (n > k) {
        cout << 0 << endl;
        return 0;
    }

    using Int = modint<MOD>;
    Combination<Int> comb(k+1);

    cout << comb.C(k, n) * comb.fact(n) << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

