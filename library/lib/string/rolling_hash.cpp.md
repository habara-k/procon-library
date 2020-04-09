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


# :heavy_check_mark: lib/string/rolling_hash.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a48db5fb6f746df590a3d4604f6478b">lib/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/string/rolling_hash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-10 03:27:47+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/string/rolling_hash/rolling_hash.test.cpp.html">test/string/rolling_hash/rolling_hash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

struct RollingHash {
    using uint = uint64_t;
    vector<uint> hash, pow;
    static const uint MASK30 = (1LL<<30)-1,
                      MASK31 = (1LL<<31)-1,
                      MASK61 = (1LL<<61)-1;

    template<typename S>
    RollingHash(const S& s, uint base) {
        int n = s.size();
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i+1] = _mod(_mul(hash[i], base) + s[i]);
            pow[i+1] = _mul(pow[i], base);
        }
    }

    uint get(int l, int r) const {
        return _mod(hash[r] + MASK61 - _mul(hash[l], pow[r - l]));
    }

    static uint _mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
             bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return _mod(au*bu*2 + mu + (md<<31) + ad*bd);
    }
    static uint _mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
        return ret;
    }
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution<uint> dist(2, MASK61-2);
        return dist(random);
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

#line 2 "lib/string/rolling_hash.cpp"

struct RollingHash {
    using uint = uint64_t;
    vector<uint> hash, pow;
    static const uint MASK30 = (1LL<<30)-1,
                      MASK31 = (1LL<<31)-1,
                      MASK61 = (1LL<<61)-1;

    template<typename S>
    RollingHash(const S& s, uint base) {
        int n = s.size();
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i+1] = _mod(_mul(hash[i], base) + s[i]);
            pow[i+1] = _mul(pow[i], base);
        }
    }

    uint get(int l, int r) const {
        return _mod(hash[r] + MASK61 - _mul(hash[l], pow[r - l]));
    }

    static uint _mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
             bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return _mod(au*bu*2 + mu + (md<<31) + ad*bd);
    }
    static uint _mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
        return ret;
    }
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution<uint> dist(2, MASK61-2);
        return dist(random);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

