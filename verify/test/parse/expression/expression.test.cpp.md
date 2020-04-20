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


# :x: test/parse/expression/expression.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ca279a26f97f9db81ddd3e8037617691">test/parse/expression</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/parse/expression/expression.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109</a>


## Depends on

* :x: <a href="../../../../library/lib/parse/expression.cpp.html">lib/parse/expression.cpp</a>
* :x: <a href="../../../../library/lib/parse/parser.cpp.html">lib/parse/parser.cpp</a>
* :question: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109"

#include "../../../lib/parse/expression.cpp"

int main()
{
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        State begin = s.begin();
        cout << expression(begin) << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/parse/expression/expression.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109"

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


#line 2 "lib/parse/parser.cpp"

using State = string::const_iterator;
class ParseError {};
#line 2 "lib/parse/expression.cpp"

int number(State& begin) {
    int ret = 0;
    while ('0' <= *begin and *begin <= '9') {
        ret *= 10;
        ret += *begin - '0';
        ++begin;
    }
    return ret;
}

int expression(State& begin);

int factor(State& begin) {
    if (*begin == '(') {
        ++begin;
        int ret = expression(begin);
        if (*begin != ')') {
            throw ParseError();
        }
        ++begin;
        return ret;
    } else {
        return number(begin);
    }
}

int term(State& begin) {
    int prod = factor(begin);
    while (true) {
        if (*begin == '*') {
            ++begin;
            prod *= factor(begin);
        }
        else if (*begin == '/') {
            ++begin;
            prod /= factor(begin);
        }
        else {
            return prod;
        }
    }
}

int expression(State& begin) {
    int sum = term(begin);
    while (true) {
        if (*begin == '+') {
            ++begin;
            sum += term(begin);
        } else if (*begin == '-') {
            ++begin;
            sum -= term(begin);
        } else {
            return sum;
        }
    }
}
#line 4 "test/parse/expression/expression.test.cpp"

int main()
{
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        State begin = s.begin();
        cout << expression(begin) << endl;
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

