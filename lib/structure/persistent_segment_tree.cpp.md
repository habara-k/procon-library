---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
    title: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x)\
    \ begin(x),end(x)\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios\
    \ {\n    fast_ios() {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll\
    \ = long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) {\
    \ a = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T\
    \ &a, T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\n\
    template<class T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/persistent_segment_tree.cpp\"\
    \n\ntemplate<typename M>\nstruct PersistentSegmentTree {\n    struct Node {\n\
    \        Node *l, *r;\n        M data;\n        Node() : l(nullptr), r(nullptr)\
    \ {}\n    };\n\n    const function<M(M,M)> f;\n    const M e;\n    const int sz;\n\
    \n    PersistentSegmentTree(const function<M(M,M)>& f, const M& e, int sz) :\n\
    \        f(f), e(e), sz(sz) {}\n\n    Node* _new(const M& data) const {\n    \
    \    auto t = new Node();\n        t->data = data;\n        return t;\n    }\n\
    \n    Node* _new(Node* l, Node* r) const {\n        auto t = new Node();\n   \
    \     t->l = l, t->r = r, t->data = f(l->data, r->data);\n        return t;\n\
    \    }\n\n    Node* _build(int l, int r) const {\n        assert(l < r);\n   \
    \     if (l+1 == r) return _new(e);\n        return _new(_build(l, (l+r)>>1),\
    \ _build((l+r)>>1, r));\n    }\n\n    Node* build() const {\n        return _build(0,\
    \ sz);\n    }\n\n    template<typename UpdateQuery>\n    Node* _update(Node* t,\
    \ const UpdateQuery& q, int pos, int l, int r) const {\n        if (pos == l and\
    \ pos+1 == r) return _new(q(t->data));\n        if (r <= pos or pos < l) return\
    \ t;\n        return _new(_update(t->l, q, pos, l, (l+r)>>1),\n              \
    \      _update(t->r, q, pos, (l+r)>>1, r));\n    }\n\n    template<typename UpdateQuery>\n\
    \    Node* update(Node* root, int pos, const UpdateQuery& q) const {\n       \
    \ return _update(root, q, pos, 0, sz);\n    }\n\n    M _query(Node* t, int a,\
    \ int b, int l, int r) const {\n        if (r <= a or b <= l) return e;\n    \
    \    if (a <= l and r <= b) return t->data;\n        return f(_query(t->l, a,\
    \ b, l, (l+r)>>1),\n                 _query(t->r, a, b, (l+r)>>1, r));\n    }\n\
    \n    M query(Node* root, int a, int b) const {\n        // return f[a,b)\n  \
    \      return _query(root, a, b, 0, sz);\n    }\n\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename M>\nstruct PersistentSegmentTree\
    \ {\n    struct Node {\n        Node *l, *r;\n        M data;\n        Node()\
    \ : l(nullptr), r(nullptr) {}\n    };\n\n    const function<M(M,M)> f;\n    const\
    \ M e;\n    const int sz;\n\n    PersistentSegmentTree(const function<M(M,M)>&\
    \ f, const M& e, int sz) :\n        f(f), e(e), sz(sz) {}\n\n    Node* _new(const\
    \ M& data) const {\n        auto t = new Node();\n        t->data = data;\n  \
    \      return t;\n    }\n\n    Node* _new(Node* l, Node* r) const {\n        auto\
    \ t = new Node();\n        t->l = l, t->r = r, t->data = f(l->data, r->data);\n\
    \        return t;\n    }\n\n    Node* _build(int l, int r) const {\n        assert(l\
    \ < r);\n        if (l+1 == r) return _new(e);\n        return _new(_build(l,\
    \ (l+r)>>1), _build((l+r)>>1, r));\n    }\n\n    Node* build() const {\n     \
    \   return _build(0, sz);\n    }\n\n    template<typename UpdateQuery>\n    Node*\
    \ _update(Node* t, const UpdateQuery& q, int pos, int l, int r) const {\n    \
    \    if (pos == l and pos+1 == r) return _new(q(t->data));\n        if (r <= pos\
    \ or pos < l) return t;\n        return _new(_update(t->l, q, pos, l, (l+r)>>1),\n\
    \                    _update(t->r, q, pos, (l+r)>>1, r));\n    }\n\n    template<typename\
    \ UpdateQuery>\n    Node* update(Node* root, int pos, const UpdateQuery& q) const\
    \ {\n        return _update(root, q, pos, 0, sz);\n    }\n\n    M _query(Node*\
    \ t, int a, int b, int l, int r) const {\n        if (r <= a or b <= l) return\
    \ e;\n        if (a <= l and r <= b) return t->data;\n        return f(_query(t->l,\
    \ a, b, l, (l+r)>>1),\n                 _query(t->r, a, b, (l+r)>>1, r));\n  \
    \  }\n\n    M query(Node* root, int a, int b) const {\n        // return f[a,b)\n\
    \        return _query(root, a, b, 0, sz);\n    }\n\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/persistent_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
documentation_of: lib/structure/persistent_segment_tree.cpp
layout: document
redirect_from:
- /library/lib/structure/persistent_segment_tree.cpp
- /library/lib/structure/persistent_segment_tree.cpp.html
title: lib/structure/persistent_segment_tree.cpp
---
