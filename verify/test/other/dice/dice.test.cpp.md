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


# :heavy_check_mark: test/other/dice/dice.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#52aab48b43ac22a8f2809e035c95fb47">test/other/dice</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/other/dice/dice.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-08 01:47:54+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/other/dice.cpp.html">lib/other/dice.cpp</a>
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

// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

// std::vector Declaration and Initialization
template<typename T>
vector<T> make_vector(size_t a, T x) { return vector<T>(a, x); }
template<typename T, typename U, typename... Ts>
auto make_vector(size_t a, U b, Ts... ts) {
    return vector<decltype(make_vector<T>(b,ts...))>(a, make_vector<T>(b, ts...));
}

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) is >> e;
    return is;
}

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::array Debug
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::deque Debug
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& d) {
    os << "[";
    bool a = 1;
    for (auto e : d) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::multiset Debug
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool a = 1;
    for (auto e : mp) {
        os << (a ? "" : " ");
        os << e.first << ":" << e.second;
        a = 0;
    }
    os << "}";
    return os;
}

// std::tuple Debug
template<int N, class Tuple>
void out(ostream& os, const Tuple& t){}
template<int N, class Tuple, class H, class ...Ts>
void out(ostream& os, const Tuple& t) {
    if (N) os << " ";
    os << get<N>(t);
    out<N+1,Tuple,Ts...>(os, t);
}
template<class ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0,tuple<Ts...>,Ts...>(os, t);
    os << ")";
    return os;
}

// Debug
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

// Weighted edge
template<typename T>
struct edge {
    int src, to;
    T cost;

    edge() {}
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

using LL = int64_t;

#define fs first
#define sc second

const int64_t MOD = 1e9+7;

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

