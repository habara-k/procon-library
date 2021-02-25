---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/tree/centroid_decomposition.cpp\"\n\nstruct\
    \ CentroidDecomposition {\n    int n, root;\n    vector<vector<int>> g, t;\n\n\
    \    CentroidDecomposition(const vector<vector<int>>& g) :\n    n(g.size()), g(g),\
    \ t(n), sz(n), split(n) {\n        root = build(0);\n    }\n\nprivate:\n    vector<int>\
    \ sz;\n    vector<bool> split;\n\n    int build_size(int u, int p) {\n       \
    \ sz[u] = 1;\n        for (int v : g[u]) {\n            if (v == p or split[v])\
    \ continue;\n            sz[u] += build_size(v, u);\n        }\n        return\
    \ sz[u];\n    }\n    int get_centroid(int u, int p, int mid) {\n        for (int\
    \ v : g[u]) {\n            if (v == p or split[v]) continue;\n            if (sz[v]\
    \ > mid) return get_centroid(v, u, mid);\n        }\n        return u;\n    }\n\
    \n    int build(int u) {\n        int cent = get_centroid(u, -1, build_size(u,\
    \ -1) / 2);\n        split[cent] = true;\n        for (int v : g[cent]) {\n  \
    \          if (!split[v]) t[cent].emplace_back(build(v));\n        }\n       \
    \ split[cent] = false;\n        return cent;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct CentroidDecomposition {\n    int n,\
    \ root;\n    vector<vector<int>> g, t;\n\n    CentroidDecomposition(const vector<vector<int>>&\
    \ g) :\n    n(g.size()), g(g), t(n), sz(n), split(n) {\n        root = build(0);\n\
    \    }\n\nprivate:\n    vector<int> sz;\n    vector<bool> split;\n\n    int build_size(int\
    \ u, int p) {\n        sz[u] = 1;\n        for (int v : g[u]) {\n            if\
    \ (v == p or split[v]) continue;\n            sz[u] += build_size(v, u);\n   \
    \     }\n        return sz[u];\n    }\n    int get_centroid(int u, int p, int\
    \ mid) {\n        for (int v : g[u]) {\n            if (v == p or split[v]) continue;\n\
    \            if (sz[v] > mid) return get_centroid(v, u, mid);\n        }\n   \
    \     return u;\n    }\n\n    int build(int u) {\n        int cent = get_centroid(u,\
    \ -1, build_size(u, -1) / 2);\n        split[cent] = true;\n        for (int v\
    \ : g[cent]) {\n            if (!split[v]) t[cent].emplace_back(build(v));\n \
    \       }\n        split[cent] = false;\n        return cent;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/tree/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/tree/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/lib/tree/centroid_decomposition.cpp
- /library/lib/tree/centroid_decomposition.cpp.html
title: lib/tree/centroid_decomposition.cpp
---
