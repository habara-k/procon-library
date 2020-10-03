---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/weighted_union_find/weighted_union_find.test.cpp
    title: test/structure/weighted_union_find/weighted_union_find.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\n\
    using vll = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
    // }}}\n\n\n// macro {{{\n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define\
    \ RREP(i,n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i,a,n) for (int i=(a);\
    \ i<(n); ++i)\n#define RFOR(i,a,n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define\
    \ SZ(x) ((int)(x).size())\n#define all(x) begin(x),end(x)\n// }}}\n\n\n// debug\
    \ {{{\n#define dump(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define debug(x) cerr<<#x<<\"\
    \ = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<< endl;\n\ntemplate<typename T>\nostream&\
    \ operator<<(ostream& os, const vector<T>& v) {\n    os << \"[\";\n    REP (i,\
    \ SZ(v)) {\n        if (i) os << \", \";\n        os << v[i];\n    }\n    return\
    \ os << \"]\";\n}\n\ntemplate<typename T, typename U>\nostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    return os << \"(\" << p.first << \" \" << p.second\
    \ << \")\";\n}\n// }}}\n\n\n// chmax, chmin {{{\ntemplate<class T>\nbool chmax(T&\
    \ a, const T& b) {\n    if (a < b) { a = b; return true; }\n    return false;\n\
    }\ntemplate<class T>\nbool chmin(T& a, const T& b) {\n    if (b < a) { a = b;\
    \ return true; }\n    return false;\n}\n// }}}\n\n\n// constants {{{\n#define\
    \ inf(T) (numeric_limits<T>::max() / 2)\nconst ll MOD = 1e9+7;\nconst ld EPS =\
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/structure/weighted_union_find.cpp\"\n\ntemplate<typename\
    \ A>\nstruct WeightedUnionFind\n{\n    vector<int> par, sz;\n    vector<A> data;\
    \     // data[x]: diff from root to x\n    WeightedUnionFind(int n, A e=0) :\n\
    \        par(n), sz(n, 1), data(n, e) {\n        for (int i = 0; i < n; ++i) par[i]\
    \ = i;\n    }\n\n    int root(int x) {\n        if (par[x] == x) return x;\n \
    \       int r = root(par[x]);\n        data[x] += data[par[x]];\n        return\
    \ par[x] = r;\n    }\n\n    A weight(int x) {\n        root(x);\n        return\
    \ data[x];\n    }\n\n    A diff(int x, int y) {\n        // diff from x to y\n\
    \        return data[y] - data[x];\n    }\n\n    void merge(int x, int y, A w)\
    \ {\n        // merge so that \"diff from x to y\" will be w.\n        w += weight(x);\
    \ w -= weight(y);\n        x = root(x); y = root(y);\n        if (x == y) return;\n\
    \        if (sz[x] < sz[y]) swap(x, y), w = -w;\n        par[y] = x;\n       \
    \ sz[x] += sz[y];\n        sz[y] = 0;\n        data[y] = w;\n    }\n\n    bool\
    \ issame(int x, int y) {\n        return root(x) == root(y);\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename A>\nstruct WeightedUnionFind\n\
    {\n    vector<int> par, sz;\n    vector<A> data;     // data[x]: diff from root\
    \ to x\n    WeightedUnionFind(int n, A e=0) :\n        par(n), sz(n, 1), data(n,\
    \ e) {\n        for (int i = 0; i < n; ++i) par[i] = i;\n    }\n\n    int root(int\
    \ x) {\n        if (par[x] == x) return x;\n        int r = root(par[x]);\n  \
    \      data[x] += data[par[x]];\n        return par[x] = r;\n    }\n\n    A weight(int\
    \ x) {\n        root(x);\n        return data[x];\n    }\n\n    A diff(int x,\
    \ int y) {\n        // diff from x to y\n        return data[y] - data[x];\n \
    \   }\n\n    void merge(int x, int y, A w) {\n        // merge so that \"diff\
    \ from x to y\" will be w.\n        w += weight(x); w -= weight(y);\n        x\
    \ = root(x); y = root(y);\n        if (x == y) return;\n        if (sz[x] < sz[y])\
    \ swap(x, y), w = -w;\n        par[y] = x;\n        sz[x] += sz[y];\n        sz[y]\
    \ = 0;\n        data[y] = w;\n    }\n\n    bool issame(int x, int y) {\n     \
    \   return root(x) == root(y);\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/weighted_union_find.cpp
  requiredBy: []
  timestamp: '2020-04-20 18:48:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/weighted_union_find/weighted_union_find.test.cpp
documentation_of: lib/structure/weighted_union_find.cpp
layout: document
redirect_from:
- /library/lib/structure/weighted_union_find.cpp
- /library/lib/structure/weighted_union_find.cpp.html
title: lib/structure/weighted_union_find.cpp
---
