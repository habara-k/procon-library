---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/lazy_randomized_binary_search_tree.cpp
    title: lib/structure/lazy_randomized_binary_search_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n\
    #define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios()\
    \ {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n  \
    \      cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll =\
    \ long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a\
    \ = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a,\
    \ T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const map<T, U> &mp);\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '[';\n\
    \    REP(i, v.size()) {\n        if (i) os << ',';\n        os << v[i];\n    }\n\
    \    return os << ']';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    return os << '(' << p.first << ' ' << p.second\
    \ << ')';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream &os, const\
    \ map<T, U> &mp) {\n    os << '{';\n    for (const auto &p : mp) {\n        os\
    \ << p << endl;\n    }\n    return os << '}';\n}\n\nconst int INF = numeric_limits<int>::max();\n\
    const ll LINF = numeric_limits<ll>::max();\n\ntemplate<class T>\nstruct edge {\n\
    \    int from, to; T cost;\n    edge(int to, T cost) :\n        from(-1), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost) :\n        from(from), to(to),\
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/lazy_randomized_binary_search_tree.cpp\"\
    \n\ntemplate<typename M, typename OM = M>\nstruct LazyRandomizedBinarySearchTree\
    \ {\n\n    struct Node {\n        Node *lch, *rch;\n        int sz;\n        M\
    \ data, sum;\n        OM lazy;\n        Node(const M& data, const OM& lazy) :\n\
    \            lch(nullptr), rch(nullptr), sz(1),\n            data(data), sum(data),\
    \ lazy(lazy) {}\n    };\n\n    const function<M(M,M)> f;\n    const function<M(M,OM,int)>\
    \ g;\n    const function<OM(OM,OM)> h;\n    const M e;\n    const OM oe;\n   \
    \ Node* root;\n    std::mt19937 random{std::random_device{}()};\n\n    LazyRandomizedBinarySearchTree(\n\
    \            const function<M(M,M)>& f,\n            const function<M(M,OM,int)>&\
    \ g,\n            const function<OM(OM,OM)>& h,\n            const M& e, const\
    \ OM& oe\n            ) : f(f), g(g), h(h), e(e), oe(oe), root(nullptr) {}\n\n\
    \    Node* _build(const vector<M>& v, int l, int r) {\n        if (l+1 >= r) return\
    \ _new(v[l]);\n        return merge(_build(v, l, (l+r)>>1),\n                \
    \     _build(v, (l+r)>>1, r));\n    }\n    void build(const vector<M>& v) { root\
    \ = _build(v, 0, v.size()); }\n\n    Node* _build(int l, int r) {\n        if\
    \ (l+1 >= r) return _new(e);\n        return merge(_build(l, (l+r)>>1),\n    \
    \                 _build((l+r)>>1, r));\n    }\n    void build(int size) { root\
    \ = _build(0, size); }\n\n    inline Node* _new(const M& data) const { return\
    \ new Node(data, oe); }\n\n    inline int size(Node* t) const { return t ? t->sz\
    \ : 0; }\n    inline M sum(Node* t) const { return t ? t->sum : e; }\n    inline\
    \ OM lazy(Node* t) const { return t ? t->lazy : oe; }\n\n    inline Node* modify(Node\
    \ *t) {\n        t->sz = size(t->lch) + size(t->rch) + 1;\n        t->sum = f(f(sum(t->lch),\
    \ t->data), sum(t->rch));\n        return t;\n    }\n\n    // Lazy Segment Tree\n\
    \    Node* propagate(Node* t) {\n        if (!t) return t;\n        if (lazy(t)\
    \ == oe) return t;\n        if (t->lch != nullptr) {\n            t->lch->lazy\
    \ = h(lazy(t->lch), lazy(t));\n            t->lch->sum = g(sum(t->lch), lazy(t),\
    \ size(t->lch));\n        }\n        if (t->rch != nullptr) {\n            t->rch->lazy\
    \ = h(lazy(t->rch), lazy(t));\n            t->rch->sum = g(sum(t->rch), lazy(t),\
    \ size(t->rch));\n        }\n        t->data = g(t->data, lazy(t), 1);\n     \
    \   t->lazy = oe;\n        return modify(t);\n    }\n\n    void update(int a,\
    \ int b, const OM& lazy) {\n        // data[a, b) = g(data[a, b), lazy)\n    \
    \    auto p0 = split(root, a);\n        auto p1 = split(p0.second, b-a);\n   \
    \     p1.first->lazy = h(p1.first->lazy, lazy);\n        p1.first = propagate(p1.first);\n\
    \        root = merge(p0.first, merge(p1.first, p1.second));\n    }\n\n    M query(int\
    \ a, int b) {\n        // return f[a,b)\n        auto p0 = split(root, a);\n \
    \       auto p1 = split(p0.second, b-a);\n        p1.first = propagate(p1.first);\n\
    \        M ret = sum(p1.first);\n        root = merge(p0.first, merge(p1.first,\
    \ p1.second));\n        return ret;\n    }\n\n\n    // Binary Search Tree\n  \
    \  Node* merge(Node *l, Node *r) {\n        if (!l) return r;\n        if (!r)\
    \ return l;\n        std::uniform_int_distribution<> dist(1,size(l)+size(r));\n\
    \        if (dist(random) > size(l)) {\n            r = propagate(r);\n      \
    \      r->lch = merge(l, r->lch);\n            return modify(r);\n        } else\
    \ {\n            l = propagate(l);\n            l->rch = merge(l->rch, r);\n \
    \           return modify(l);\n        }\n    }\n\n    pair<Node*, Node*> split(Node*\
    \ t, int k) {\n        if (!t) return {t, t};\n        t = propagate(t);\n   \
    \     if (k > size(t->lch)) {\n            auto p = split(t->rch, k-size(t->lch)-1);\n\
    \            t->rch = p.first;\n            return {modify(t), p.second};\n  \
    \      } else {\n            auto p = split(t->lch, k);\n            t->lch =\
    \ p.second;\n            return {p.first, modify(t)};\n        }\n    }\n\n  \
    \  void insert(int k, const M& data) {\n        auto q = _new(data);\n       \
    \ auto p = split(root, k);\n        root = merge(merge(p.first, q), p.second);\n\
    \    }\n\n    M erase(int k) {\n        auto p = split(root, k);\n        auto\
    \ q = split(p.second, 1);\n        M ret = q.first->data;\n        root = merge(p.first,\
    \ q.second);\n        return ret;\n    }\n\n    M operator[](int i) {\n      \
    \  return query(i, i+1);\n    }\n\n    friend ostream& operator<<(ostream& os,\n\
    \            LazyRandomizedBinarySearchTree& tr) {\n        os << \"[\";\n   \
    \     for (int i = 0; i < tr.root->sz; ++i) {\n            if (i) os << \" \"\
    ;\n            os << tr[i];\n        }\n        return os << \"]\";\n    }\n};\n\
    #line 4 \"test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    LazyRandomizedBinarySearchTree<int64_t>\
    \ tr(\n            [](int64_t a, int64_t b){ return a + b; },\n            [](int64_t\
    \ a, int64_t b, int w){ return b*w; },\n            [](int64_t a, int64_t b){\
    \ return b; },\n            0, numeric_limits<int64_t>::max());\n    tr.build(N);\n\
    \n    while (Q--) {\n        int C; cin >> C;\n        if (C == 0) {\n       \
    \     int S, T; int X;\n            cin >> S >> T >> X;\n            tr.update(S,\
    \ T+1, X);\n        } else {\n            int S, T;\n            cin >> S >> T;\n\
    \            cout << tr.query(S, T+1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n\n#include \"../../../lib/structure/lazy_randomized_binary_search_tree.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    LazyRandomizedBinarySearchTree<int64_t>\
    \ tr(\n            [](int64_t a, int64_t b){ return a + b; },\n            [](int64_t\
    \ a, int64_t b, int w){ return b*w; },\n            [](int64_t a, int64_t b){\
    \ return b; },\n            0, numeric_limits<int64_t>::max());\n    tr.build(N);\n\
    \n    while (Q--) {\n        int C; cin >> C;\n        if (C == 0) {\n       \
    \     int S, T; int X;\n            cin >> S >> T >> X;\n            tr.update(S,\
    \ T+1, X);\n        } else {\n            int S, T;\n            cin >> S >> T;\n\
    \            cout << tr.query(S, T+1) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - lib/structure/lazy_randomized_binary_search_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp
layout: document
redirect_from:
- /verify/test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp
- /verify/test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp.html
title: test/structure/lazy_randomized_binary_search_tree/rsq_ruq.test.cpp
---
