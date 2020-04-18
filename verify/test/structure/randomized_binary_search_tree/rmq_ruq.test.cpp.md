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


# :heavy_check_mark: test/structure/randomized_binary_search_tree/rmq_ruq.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c596028d317fdbd8ee456ffe90ba6e35">test/structure/randomized_binary_search_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/randomized_binary_search_tree/rmq_ruq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-10 03:29:50+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/structure/randomized_binary_search_tree.cpp.html">lib/structure/randomized_binary_search_tree.cpp</a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../../lib/structure/randomized_binary_search_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RandomizedBinarySearchTree<int64_t> ruq(
            [](int64_t a, int64_t b){ return min(a,b); },
            [](int64_t a, int64_t b, int w){ return b; },
            [](int64_t a, int64_t b){ return b; },
            (1LL<<31)-1, numeric_limits<int64_t>::max());
    ruq.build(N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            ruq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << ruq.query(S, T+1) << endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/randomized_binary_search_tree/rmq_ruq.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

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

#line 2 "lib/structure/randomized_binary_search_tree.cpp"

template<typename M, typename OM = M>
struct RandomizedBinarySearchTree {

    struct Node {
        Node *lch, *rch;
        int sz;
        M data, sum;
        OM lazy;
        Node(const M& data, const OM& lazy) :
            lch(nullptr), rch(nullptr), sz(1),
            data(data), sum(data), lazy(lazy) {}
    };

    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    const M e;
    const OM oe;
    Node* root;
    std::mt19937 random{std::random_device{}()};

    RandomizedBinarySearchTree(
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h,
            const M& e, const OM& oe
            ) : f(f), g(g), h(h), e(e), oe(oe), root(nullptr) {}

    Node* _build(const vector<M>& v, int l, int r) {
        if (l+1 >= r) return _new(v[l]);
        return merge(_build(v, l, (l+r)>>1),
                     _build(v, (l+r)>>1, r));
    }
    void build(const vector<M>& v) { root = _build(v, 0, v.size()); }

    Node* _build(int l, int r) {
        if (l+1 >= r) return _new(e);
        return merge(_build(l, (l+r)>>1),
                     _build((l+r)>>1, r));
    }
    void build(int size) { root = _build(0, size); }

    inline Node* _new(const M& data) { return new Node(data, oe); }

    inline int size(Node* t) const { return t ? t->sz : 0; }
    inline M sum(Node* t) const { return t ? t->sum : e; }
    inline OM lazy(Node* t) const { return t ? t->lazy : oe; }

    inline Node* modify(Node *t) {
        t->sz = size(t->lch) + size(t->rch) + 1;
        t->sum = f(f(sum(t->lch), t->data), sum(t->rch));
        return t;
    }

    // Lazy Segment Tree
    Node* propagate(Node* t) {
        if (!t) return t;
        if (lazy(t) == oe) return t;
        if (t->lch != nullptr) {
            t->lch->lazy = h(lazy(t->lch), lazy(t));
            t->lch->sum = g(sum(t->lch), lazy(t), size(t->lch));
        }
        if (t->rch != nullptr) {
            t->rch->lazy = h(lazy(t->rch), lazy(t));
            t->rch->sum = g(sum(t->rch), lazy(t), size(t->rch));
        }
        t->data = g(t->data, lazy(t), 1);
        t->lazy = oe;
        return modify(t);
    }

    void update(int a, int b, const OM& lazy) {
        // data[a, b) = g(data[a, b), lazy)
        auto p0 = split(root, a);
        auto p1 = split(p0.second, b-a);
        p1.first->lazy = h(p1.first->lazy, lazy);
        p1.first = propagate(p1.first);
        root = merge(p0.first, merge(p1.first, p1.second));
    }

    M query(int a, int b) {
        // return f[a,b)
        auto p0 = split(root, a);
        auto p1 = split(p0.second, b-a);
        p1.first = propagate(p1.first);
        M ret = sum(p1.first);
        root = merge(p0.first, merge(p1.first, p1.second));
        return ret;
    }


    // Binary Search Tree
    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        std::uniform_int_distribution<> dist(1,size(l)+size(r));
        if (dist(random) > size(l)) {
            r = propagate(r);
            r->lch = merge(l, r->lch);
            return modify(r);
        } else {
            l = propagate(l);
            l->rch = merge(l->rch, r);
            return modify(l);
        }
    }

    pair<Node*, Node*> split(Node* t, int k) {
        if (!t) return {t, t};
        t = propagate(t);
        if (k > size(t->lch)) {
            auto p = split(t->rch, k-size(t->lch)-1);
            t->rch = p.first;
            return {modify(t), p.second};
        } else {
            auto p = split(t->lch, k);
            t->lch = p.second;
            return {p.first, modify(t)};
        }
    }

    void insert(int k, const M& data) {
        auto q = _new(data);
        auto p = split(root, k);
        root = merge(merge(p.first, q), p.second);
    }

    M erase(int k) {
        auto p = split(root, k);
        auto q = split(p.second, 1);
        M ret = q.first->data;
        root = merge(p.first, q.second);
        return ret;
    }

    void print(Node* t) {
        if (!t) return;
        if (t->lch) { cout << "("; print(t->lch); cout << ")"; }
        cout << t->data;
        if (t->rch) { cout << "("; print(t->rch); cout << ")"; }
    }
    void print_sum(Node* t) {
        if (!t) return;
        if (t->lch) { cout << "("; print(t->lch); cout << ")"; }
        cout << sum(t);
        if (t->rch) { cout << "("; print(t->rch); cout << ")"; }
    }
    void print_lazy(Node* t) {
        if (!t) return;
        if (t->lch) { cout << "("; print(t->lch); cout << ")"; }
        cout << lazy(t);
        if (t->rch) { cout << "("; print(t->rch); cout << ")"; }
    }

    friend ostream& operator<<(ostream& os, RandomizedBinarySearchTree& tr) {
        os << "data: "; tr.print(tr.root); os << endl;
        os << " sum: "; tr.print_sum(tr.root); os << endl;
        os << "lazy: "; tr.print_lazy(tr.root); os << endl;
        return os;
    }
};
#line 4 "test/structure/randomized_binary_search_tree/rmq_ruq.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RandomizedBinarySearchTree<int64_t> ruq(
            [](int64_t a, int64_t b){ return min(a,b); },
            [](int64_t a, int64_t b, int w){ return b; },
            [](int64_t a, int64_t b){ return b; },
            (1LL<<31)-1, numeric_limits<int64_t>::max());
    ruq.build(N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; int X;
            cin >> S >> T >> X;
            ruq.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << ruq.query(S, T+1) << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

