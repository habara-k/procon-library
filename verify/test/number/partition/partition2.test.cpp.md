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


# :x: test/number/partition/partition2.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#48198b7eaf65467b49c6ef390bc37e8f">test/number/partition</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/partition/partition2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L</a>


## Depends on

* :question: <a href="../../../../library/lib/number/modint.cpp.html">lib/number/modint.cpp</a>
* :question: <a href="../../../../library/lib/number/partition.cpp.html">lib/number/partition.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"

#include "../../../lib/number/modint.cpp"
#include "../../../lib/number/partition.cpp"

int main() {
    int n, k; cin >> n >> k;

    using Int = modint<MOD>;
    cout << Partition<Int>(k, n) - Partition<Int>(k-1, n) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/partition/partition2.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"

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
#line 2 "lib/number/partition.cpp"

// 分割数
// Partition(k, n) := 区別できないn 個のボールを
//                    区別できないk 個の箱に入れる場合の数
template<typename Ring>
Ring Partition(int k, int n) {
    vector<vector<Ring>> part(k+1, vector<Ring>(n+1));
    part[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j-i >= 0) {
                part[i][j] = part[i-1][j] + part[i][j-i];
            } else {
                part[i][j] = part[i-1][j];
            }
        }
    }
    return part[k][n];
}
#line 5 "test/number/partition/partition2.test.cpp"

int main() {
    int n, k; cin >> n >> k;

    using Int = modint<MOD>;
    cout << Partition<Int>(k, n) - Partition<Int>(k-1, n) << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

