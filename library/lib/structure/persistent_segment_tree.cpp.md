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


# :heavy_check_mark: lib/structure/persistent_segment_tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/persistent_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-12 12:38:19+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp.html">test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename M>
struct PersistentSegmentTree {
    struct Node {
        Node *l, *r;
        M data;
        Node() : l(nullptr), r(nullptr) {}
    };

    const function<M(M,M)> f;
    const M e;
    const int sz;

    PersistentSegmentTree(const function<M(M,M)>& f, const M& e, int sz) :
        f(f), e(e), sz(sz) {}

    Node* _new(const M& data) {
        auto t = new Node();
        t->data = data;
        return t;
    }

    Node* _new(Node* l, Node* r) {
        auto t = new Node();
        t->l = l, t->r = r, t->data = f(l->data, r->data);
        return t;
    }

    Node* _build(int l, int r) {
        assert(l < r);
        if (l+1 == r) return _new(e);
        return _new(_build(l, (l+r)>>1), _build((l+r)>>1, r));
    }

    Node* build() {
        return _build(0, sz);
    }

    template<typename UpdateQuery>
    Node* _update(Node* t, const UpdateQuery& q, int pos, int l, int r) {
        if (pos == l and pos+1 == r) return _new(q(t->data));
        if (r <= pos or pos < l) return t;
        return _new(_update(t->l, q, pos, l, (l+r)>>1),
                    _update(t->r, q, pos, (l+r)>>1, r));
    }

    template<typename UpdateQuery>
    Node* update(Node* root, const UpdateQuery& q, int pos) {
        return _update(root, q, pos, 0, sz);
    }

    M _query(Node* t, int a, int b, int l, int r) {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return t->data;
        return f(_query(t->l, a, b, l, (l+r)>>1),
                 _query(t->r, a, b, (l+r)>>1, r));
    }

    M query(Node* root, int a, int b) {
        // return f[a,b)
        return _query(root, a, b, 0, sz);
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

#line 2 "lib/structure/persistent_segment_tree.cpp"

template<typename M>
struct PersistentSegmentTree {
    struct Node {
        Node *l, *r;
        M data;
        Node() : l(nullptr), r(nullptr) {}
    };

    const function<M(M,M)> f;
    const M e;
    const int sz;

    PersistentSegmentTree(const function<M(M,M)>& f, const M& e, int sz) :
        f(f), e(e), sz(sz) {}

    Node* _new(const M& data) {
        auto t = new Node();
        t->data = data;
        return t;
    }

    Node* _new(Node* l, Node* r) {
        auto t = new Node();
        t->l = l, t->r = r, t->data = f(l->data, r->data);
        return t;
    }

    Node* _build(int l, int r) {
        assert(l < r);
        if (l+1 == r) return _new(e);
        return _new(_build(l, (l+r)>>1), _build((l+r)>>1, r));
    }

    Node* build() {
        return _build(0, sz);
    }

    template<typename UpdateQuery>
    Node* _update(Node* t, const UpdateQuery& q, int pos, int l, int r) {
        if (pos == l and pos+1 == r) return _new(q(t->data));
        if (r <= pos or pos < l) return t;
        return _new(_update(t->l, q, pos, l, (l+r)>>1),
                    _update(t->r, q, pos, (l+r)>>1, r));
    }

    template<typename UpdateQuery>
    Node* update(Node* root, const UpdateQuery& q, int pos) {
        return _update(root, q, pos, 0, sz);
    }

    M _query(Node* t, int a, int b, int l, int r) {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return t->data;
        return f(_query(t->l, a, b, l, (l+r)>>1),
                 _query(t->r, a, b, (l+r)>>1, r));
    }

    M query(Node* root, int a, int b) {
        // return f[a,b)
        return _query(root, a, b, 0, sz);
    }

};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

