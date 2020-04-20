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


# :x: test/other/dice/dice.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#52aab48b43ac22a8f2809e035c95fb47">test/other/dice</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/other/dice/dice.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181</a>


## Depends on

* :x: <a href="../../../../library/lib/other/dice.cpp.html">lib/other/dice.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181"

#include "../../../lib/other/dice.cpp"

int main()
{
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        auto h = make_v<int>(2*n+1, 2*n+1),
             v = make_v<int>(2*n+1, 2*n+1);

        for (int k = 0; k < n; ++k) {
            int t, f; cin >> t >> f;
            Dice dice(1,6,2,5,3,4);
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollF();
            if (dice.U != t) dice.rollF();
            if (dice.U != t) dice.rollF();
            if (dice.F != f) dice.rollU();
            if (dice.F != f) dice.rollU();
            if (dice.F != f) dice.rollU();
            assert(dice.F == f and dice.U == t);

            for (int i = n, j = n;;) {
                if (dice.L == 6 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 6 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 6 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 6 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else if (dice.L == 5 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 5 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 5 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 5 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else if (dice.L == 4 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 4 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 4 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 4 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else {
                    ++h[i][j];
                    v[i][j] = dice.U;
                    break;
                }
            }

        }
        vector<int> cnt(6);
        for (int i = 0; i <= 2*n; ++i) {
            for (int j = 0; j <= 2*n; ++j) {
                if (v[i][j]) ++cnt[v[i][j]-1];
            }
        }

        for (int i = 0; i < 6; ++i) {
            if (i) cout << " ";
            cout << cnt[i];
        }
        cout << endl;
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/other/dice/dice.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181"

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
#line 4 "test/other/dice/dice.test.cpp"

int main()
{
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        auto h = make_v<int>(2*n+1, 2*n+1),
             v = make_v<int>(2*n+1, 2*n+1);

        for (int k = 0; k < n; ++k) {
            int t, f; cin >> t >> f;
            Dice dice(1,6,2,5,3,4);
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollR();
            if (dice.U != t) dice.rollF();
            if (dice.U != t) dice.rollF();
            if (dice.U != t) dice.rollF();
            if (dice.F != f) dice.rollU();
            if (dice.F != f) dice.rollU();
            if (dice.F != f) dice.rollU();
            assert(dice.F == f and dice.U == t);

            for (int i = n, j = n;;) {
                if (dice.L == 6 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 6 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 6 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 6 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else if (dice.L == 5 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 5 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 5 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 5 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else if (dice.L == 4 and h[i+1][j] < h[i][j]) {
                    dice.rollB();
                    ++i;
                }
                else if (dice.R == 4 and h[i-1][j] < h[i][j]) {
                    dice.rollF();
                    --i;
                }
                else if (dice.F == 4 and h[i][j+1] < h[i][j]) {
                    dice.rollL();
                    ++j;
                }
                else if (dice.B == 4 and h[i][j-1] < h[i][j]) {
                    dice.rollR();
                    --j;
                }
                else {
                    ++h[i][j];
                    v[i][j] = dice.U;
                    break;
                }
            }

        }
        vector<int> cnt(6);
        for (int i = 0; i <= 2*n; ++i) {
            for (int j = 0; j <= 2*n; ++j) {
                if (v[i][j]) ++cnt[v[i][j]-1];
            }
        }

        for (int i = 0; i < 6; ++i) {
            if (i) cout << " ";
            cout << cnt[i];
        }
        cout << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

