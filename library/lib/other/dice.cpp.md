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


# :heavy_check_mark: lib/other/dice.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2fde05eafc6645110721cf5a4d8688d4">lib/other</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/other/dice.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/other/dice/dice.test.cpp.html">test/other/dice/dice.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

struct Dice {
    int U, D, L, R, F, B;
    Dice(int U, int D, int L, int R, int F, int B) :
        U(U), D(D), L(L), R(R), F(F), B(B) {}

    void rollU() {
        int buff = F;
        F = R; R = B; B = L; L = buff;
    }
    void rollD() {
        int buff = F;
        F = L; L = B; B = R; R = buff;
    }
    void rollF() {
        int buff = U;
        U = L; L = D; D = R; R = buff;
    }
    void rollB() {
        int buff = U;
        U = R; R = D; D = L; L = buff;
    }
    void rollR() {
        int buff = U;
        U = F; F = D; D = B; B = buff;
    }
    void rollL() {
        int buff = U;
        U = B; B = D; D = F; F = buff;
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


#line 2 "lib/other/dice.cpp"

struct Dice {
    int U, D, L, R, F, B;
    Dice(int U, int D, int L, int R, int F, int B) :
        U(U), D(D), L(L), R(R), F(F), B(B) {}

    void rollU() {
        int buff = F;
        F = R; R = B; B = L; L = buff;
    }
    void rollD() {
        int buff = F;
        F = L; L = B; B = R; R = buff;
    }
    void rollF() {
        int buff = U;
        U = L; L = D; D = R; R = buff;
    }
    void rollB() {
        int buff = U;
        U = R; R = D; D = L; L = buff;
    }
    void rollR() {
        int buff = U;
        U = F; F = D; D = B; B = buff;
    }
    void rollL() {
        int buff = U;
        U = B; B = D; D = F; F = buff;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

