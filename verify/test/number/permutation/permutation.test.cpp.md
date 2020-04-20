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


# :x: test/number/permutation/permutation.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c6ec85282d760c3c896cf33527d5c549">test/number/permutation</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/permutation/permutation.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731</a>


## Depends on

* :x: <a href="../../../../library/lib/number/permutation.cpp.html">lib/number/permutation.cpp</a>
* :x: <a href="../../../../library/lib/parse/parser.cpp.html">lib/parse/parser.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731"

#include "../../../lib/number/permutation.cpp"
#include "../../../lib/parse/parser.cpp"

int N, L;
string S;

int number(State& begin) {
    int ret = 0;
    while ('0' <= *begin and *begin <= '9') {
        ret *= 10;
        ret += *begin - '0';
        ++begin;
    }
    return ret;
}


Permutation operation(State& begin) {
    char ch = *begin;
    int num = number(++begin) - 1;
    Permutation ord(N*N);
    if (ch == 'R') {
        int buff = ord[N-1 + num*N];
        for (int i = N-1; i > 0; --i) {
            ord[i + num*N] = ord[i-1 + num*N];
        }
        ord[num*N] = buff;
    }
    if (ch == 'L') {
        int buff = ord[0 + num*N];
        for (int i = 0; i < N-1; ++i) {
            ord[i + num*N] = ord[i+1 + num*N];
        }
        ord[N-1 + num*N] = buff;
    }
    if (ch == 'D') {
        int buff = ord[num + (N-1)*N];
        for (int i = N-1; i > 0; --i) {
            ord[num + i*N] = ord[num + (i-1)*N];
        }
        ord[num] = buff;
    }
    if (ch == 'U') {
        int buff = ord[num];
        for (int i = 0; i < N-1; ++i) {
            ord[num + i*N] = ord[num + (i+1)*N];
        }
        ord[num + (N-1)*N] = buff;
    }
    return ord;
}

Permutation sequence(State& begin);

Permutation repetition(State& begin) {
    assert(*begin == '(');
    Permutation ret = sequence(++begin);
    assert(*begin == ')');
    int num = number(++begin);
    return ret.pow(num);
}

Permutation rep_or_op(State& begin) {
    if (*begin == '(') {
        return repetition(begin);
    } else {
        return operation(begin);
    }
}

Permutation sequence(State& begin) {
    Permutation ret = rep_or_op(begin);
    while (*begin != ')' and *begin != '\0') {
        ret = ret * rep_or_op(begin);
    }
    return ret;
}


int main()
{
    cin >> N >> L >> S;
    State begin = S.begin();

    Permutation perm = sequence(begin);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j) cout << " ";
            cout << perm[i*N + j] + 1;
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
#line 1 "test/number/permutation/permutation.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731"

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


#line 2 "lib/number/permutation.cpp"

struct Permutation {
    vector<int> perm;
    Permutation() {}
    Permutation(int sz) : perm(sz) {
        iota(perm.begin(), perm.end(), 0);
    }
    Permutation(initializer_list<int> init) : perm(init.begin(), init.end()) {}
    size_t size() const {
        return (perm.size());
    }
    inline int operator [](int k) const {
        return (perm.at(k));
    }
    inline int& operator [](int k) {
        return (perm.at(k));
    }
    Permutation& operator*=(const Permutation& rhs) {
        assert(size() == rhs.size());
        Permutation tmp(size());
        for (int i = 0; i < size(); ++i) {
            tmp[i] = perm[rhs[i]];
        }
        perm.swap(tmp.perm);
        return (*this);
    }
    const Permutation operator*(const Permutation& rhs) const {
        return (Permutation(*this) *= rhs);
    }
    Permutation pow(int64_t k) {
        Permutation ret(size()), tmp = *this;
        while (k) {
            if (k & 1) ret *= tmp;
            tmp *= tmp; k >>= 1;
        }
        return (ret);
    }
};
#line 2 "lib/parse/parser.cpp"

using State = string::const_iterator;
class ParseError {};
#line 5 "test/number/permutation/permutation.test.cpp"

int N, L;
string S;

int number(State& begin) {
    int ret = 0;
    while ('0' <= *begin and *begin <= '9') {
        ret *= 10;
        ret += *begin - '0';
        ++begin;
    }
    return ret;
}


Permutation operation(State& begin) {
    char ch = *begin;
    int num = number(++begin) - 1;
    Permutation ord(N*N);
    if (ch == 'R') {
        int buff = ord[N-1 + num*N];
        for (int i = N-1; i > 0; --i) {
            ord[i + num*N] = ord[i-1 + num*N];
        }
        ord[num*N] = buff;
    }
    if (ch == 'L') {
        int buff = ord[0 + num*N];
        for (int i = 0; i < N-1; ++i) {
            ord[i + num*N] = ord[i+1 + num*N];
        }
        ord[N-1 + num*N] = buff;
    }
    if (ch == 'D') {
        int buff = ord[num + (N-1)*N];
        for (int i = N-1; i > 0; --i) {
            ord[num + i*N] = ord[num + (i-1)*N];
        }
        ord[num] = buff;
    }
    if (ch == 'U') {
        int buff = ord[num];
        for (int i = 0; i < N-1; ++i) {
            ord[num + i*N] = ord[num + (i+1)*N];
        }
        ord[num + (N-1)*N] = buff;
    }
    return ord;
}

Permutation sequence(State& begin);

Permutation repetition(State& begin) {
    assert(*begin == '(');
    Permutation ret = sequence(++begin);
    assert(*begin == ')');
    int num = number(++begin);
    return ret.pow(num);
}

Permutation rep_or_op(State& begin) {
    if (*begin == '(') {
        return repetition(begin);
    } else {
        return operation(begin);
    }
}

Permutation sequence(State& begin) {
    Permutation ret = rep_or_op(begin);
    while (*begin != ')' and *begin != '\0') {
        ret = ret * rep_or_op(begin);
    }
    return ret;
}


int main()
{
    cin >> N >> L >> S;
    State begin = S.begin();

    Permutation perm = sequence(begin);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j) cout << " ";
            cout << perm[i*N + j] + 1;
        }
        cout << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

