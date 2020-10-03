---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp
    title: test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
    title: test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/lowest_common_ancestor.cpp\"\n\nstruct\
    \ LCA {\n    int n, log2_n;\n    vector<int> depth;\n    vector<vector<int>> par;\n\
    \n    void dfs(const vector<vector<int>>& G, int v, int p, int d) {\n        depth[v]\
    \ = d;\n        par[0][v] = p;\n        for (auto to : G[v]) {\n            if\
    \ (to != p) dfs(G, to, v, d+1);\n        }\n    }\n\n    LCA(const vector<vector<int>>&\
    \ G, int root=0) :\n            n(G.size()), log2_n(log2(n)), depth(n),\n    \
    \        par(log2_n+1, vector<int>(n,-1)) {\n\n        dfs(G, root, -1, 0);\n\
    \        for (int k = 0; k < log2_n; ++k) {\n            for (int v = 0; v < n;\
    \ ++v) {\n                if (par[k][v] != -1) {\n                    par[k+1][v]\
    \ = par[k][par[k][v]];\n                }\n            }\n        }\n    }\n\n\
    \    int query(int u, int v) const {\n        if (depth[u] > depth[v]) swap(u,\
    \ v);\n\n        // align the depth of u and v\n        for (int k = 0; k <= log2_n;\
    \ ++k) {\n            if ((depth[v] - depth[u]) >> k & 1) {\n                v\
    \ = par[k][v];\n            }\n        }\n        if (u == v) return u;\n\n  \
    \      // go back until u and v's parents do not match\n        for (int k = log2_n;\
    \ k >= 0; --k) {\n            if (par[k][u] != par[k][v]) {\n                u\
    \ = par[k][u];\n                v = par[k][v];\n            }\n        }\n   \
    \     return par[0][u];\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct LCA {\n    int n, log2_n;\n    vector<int>\
    \ depth;\n    vector<vector<int>> par;\n\n    void dfs(const vector<vector<int>>&\
    \ G, int v, int p, int d) {\n        depth[v] = d;\n        par[0][v] = p;\n \
    \       for (auto to : G[v]) {\n            if (to != p) dfs(G, to, v, d+1);\n\
    \        }\n    }\n\n    LCA(const vector<vector<int>>& G, int root=0) :\n   \
    \         n(G.size()), log2_n(log2(n)), depth(n),\n            par(log2_n+1, vector<int>(n,-1))\
    \ {\n\n        dfs(G, root, -1, 0);\n        for (int k = 0; k < log2_n; ++k)\
    \ {\n            for (int v = 0; v < n; ++v) {\n                if (par[k][v]\
    \ != -1) {\n                    par[k+1][v] = par[k][par[k][v]];\n           \
    \     }\n            }\n        }\n    }\n\n    int query(int u, int v) const\
    \ {\n        if (depth[u] > depth[v]) swap(u, v);\n\n        // align the depth\
    \ of u and v\n        for (int k = 0; k <= log2_n; ++k) {\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) {\n                v = par[k][v];\n            }\n   \
    \     }\n        if (u == v) return u;\n\n        // go back until u and v's parents\
    \ do not match\n        for (int k = log2_n; k >= 0; --k) {\n            if (par[k][u]\
    \ != par[k][v]) {\n                u = par[k][u];\n                v = par[k][v];\n\
    \            }\n        }\n        return par[0][u];\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/lowest_common_ancestor.cpp
  requiredBy: []
  timestamp: '2020-04-20 20:05:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/persistent_segment_tree/persistent_segment_tree.test.cpp
  - test/graph/lowest_common_ancestor/lowest_common_ancesstor.test.cpp
documentation_of: lib/graph/lowest_common_ancestor.cpp
layout: document
redirect_from:
- /library/lib/graph/lowest_common_ancestor.cpp
- /library/lib/graph/lowest_common_ancestor.cpp.html
title: lib/graph/lowest_common_ancestor.cpp
---
