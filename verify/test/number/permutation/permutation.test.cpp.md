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


# :heavy_check_mark: test/number/permutation/permutation.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c6ec85282d760c3c896cf33527d5c549">test/number/permutation</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/permutation/permutation.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 15:27:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2731</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/number/permutation.cpp.html">lib/number/permutation.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/parse/parser.cpp.html">lib/parse/parser.cpp</a>
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

