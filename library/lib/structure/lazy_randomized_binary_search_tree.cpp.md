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


# :heavy_check_mark: lib/structure/lazy_randomized_binary_search_tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/lazy_randomized_binary_search_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 18:48:42+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/structure/lazy_randomized_binary_search_tree/rmq_raq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rmq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/structure/lazy_randomized_binary_search_tree/rmq_ruq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rmq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/structure/lazy_randomized_binary_search_tree/rsq_raq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rsq_raq.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/structure/lazy_randomized_binary_search_tree/ruq.test.cpp.html">test/structure/lazy_randomized_binary_search_tree/ruq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename M, typename OM = M>
struct LazyRandomizedBinarySearchTree {

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

    LazyRandomizedBinarySearchTree(
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

    inline Node* _new(const M& data) const { return new Node(data, oe); }

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

    M operator[](int i) {
        return query(i, i+1);
    }

    friend ostream& operator<<(ostream& os,
            LazyRandomizedBinarySearchTree& tr) {
        os << "[";
        for (int i = 0; i < tr.root->sz; ++i) {
            if (i) os << " ";
            os << tr[i];
        }
        return os << "]";
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


#line 2 "lib/structure/lazy_randomized_binary_search_tree.cpp"

template<typename M, typename OM = M>
struct LazyRandomizedBinarySearchTree {

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

    LazyRandomizedBinarySearchTree(
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

    inline Node* _new(const M& data) const { return new Node(data, oe); }

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

    M operator[](int i) {
        return query(i, i+1);
    }

    friend ostream& operator<<(ostream& os,
            LazyRandomizedBinarySearchTree& tr) {
        os << "[";
        for (int i = 0; i < tr.root->sz; ++i) {
            if (i) os << " ";
            os << tr[i];
        }
        return os << "]";
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
