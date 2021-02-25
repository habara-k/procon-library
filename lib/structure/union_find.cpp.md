---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.cpp
    title: lib/graph/kruskal.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal/kruskal.test.cpp
    title: test/graph/kruskal/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/structure/union_find/union_find.test.cpp
    title: test/structure/union_find/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/tree_hash/tree_hash.test.cpp
    title: test/tree/tree_hash/tree_hash.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/union_find.cpp\"\n\nstruct UnionFind\n\
    {\n    const int n;\n    vector<int> par, sz;\n    UnionFind(int n) : n(n), par(n),\
    \ sz(n, 1) {\n        for (int i = 0; i < n; ++i) par[i] = i;\n    }\n\n    int\
    \ root(int x) {\n        if (par[x] == x) return x;\n        return par[x] = root(par[x]);\n\
    \    }\n\n    void merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return;\n        if (sz[x] < sz[y]) swap(x, y);\n       \
    \ par[y] = x;\n        sz[x] += sz[y];\n        sz[y] = 0;\n    }\n\n    bool\
    \ issame(int x, int y) {\n        return root(x) == root(y);\n    }\n\n    int\
    \ size(int x) {\n        return sz[root(x)];\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, UnionFind& uf) {\n        os << \"[\";\n        for (int i = 0; i < uf.n;\
    \ ++i) {\n            if (i > 0) os << \" \";\n            os << uf.root(i);\n\
    \        }\n        return os << \"]\" << endl;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct UnionFind\n{\n    const int n;\n \
    \   vector<int> par, sz;\n    UnionFind(int n) : n(n), par(n), sz(n, 1) {\n  \
    \      for (int i = 0; i < n; ++i) par[i] = i;\n    }\n\n    int root(int x) {\n\
    \        if (par[x] == x) return x;\n        return par[x] = root(par[x]);\n \
    \   }\n\n    void merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return;\n        if (sz[x] < sz[y]) swap(x, y);\n       \
    \ par[y] = x;\n        sz[x] += sz[y];\n        sz[y] = 0;\n    }\n\n    bool\
    \ issame(int x, int y) {\n        return root(x) == root(y);\n    }\n\n    int\
    \ size(int x) {\n        return sz[root(x)];\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, UnionFind& uf) {\n        os << \"[\";\n        for (int i = 0; i < uf.n;\
    \ ++i) {\n            if (i > 0) os << \" \";\n            os << uf.root(i);\n\
    \        }\n        return os << \"]\" << endl;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/union_find.cpp
  requiredBy:
  - lib/graph/kruskal.cpp
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/union_find/union_find.test.cpp
  - test/tree/tree_hash/tree_hash.test.cpp
  - test/graph/kruskal/kruskal.test.cpp
documentation_of: lib/structure/union_find.cpp
layout: document
redirect_from:
- /library/lib/structure/union_find.cpp
- /library/lib/structure/union_find.cpp.html
title: lib/structure/union_find.cpp
---
