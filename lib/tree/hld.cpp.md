---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/hld.test.cpp
    title: test/tree/hld/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/lca.test.cpp
    title: test/tree/hld/lca.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/tree/hld.cpp\"\n\nstruct HLDecomposition\
    \ {\n    const vector<vector<int>>& G;\n    vector<int> par, size, depth, head,\
    \ vid;\n    // par[v]: parent of v\n    // size[v]: size of subtree[v]\n    //\
    \ depth[v]: depth of v. depth[root] = 0\n    // head[v]: head of row containing\
    \ v\n    // vid[v]: index of v when all the rows are aligned.\n\n    void dfs(int\
    \ v, int p, int d) {\n        par[v] = p; depth[v] = d; size[v] = 1;\n       \
    \ for (int u : G[v]) {\n            if (u == p) continue;\n            dfs(u,\
    \ v, d+1);\n            size[v] += size[u];\n        }\n    }\n    void hld(int\
    \ v, int h, int& k) {\n        head[v] = h; vid[v] = k++;\n        int ma = 0,\
    \ id = -1;\n        for (int u : G[v]) {\n            if (u == par[v]) continue;\n\
    \            if (chmax(ma, size[u])) id = u;\n        }\n        if (id == -1)\
    \ return;\n        hld(id, h, k);\n        for (int u : G[v]) {\n            if\
    \ (u == id or u == par[v]) continue;\n            hld(u, u, k);\n        }\n \
    \   }\n\n    HLDecomposition(const vector<vector<int>>& g) :\n        G(g), par(g.size()),\
    \ size(g.size()), depth(g.size()),\n        head(g.size()), vid(g.size()) {}\n\
    \n    void build(int root = 0) {\n        dfs(root, -1, 0);\n        int k = 0;\n\
    \        hld(root, root, k);\n    }\n\n    int lca(int u, int v) const {\n   \
    \     for (;; v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]])\
    \ swap(u, v);\n            if (head[u] == head[v]) {\n                if (depth[u]\
    \ > depth[v]) swap(u, v);\n                return u;\n            }\n        }\n\
    \    }\n\n    template<typename UpdateQuery>\n    void update(int u, int v, const\
    \ UpdateQuery& q, bool edge = false) const {\n        // q(a, b): update [a, b).\n\
    \        for (;; v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]])\
    \ swap(u, v);\n            if (head[u] == head[v]) {\n                if (vid[u]\
    \ > vid[v]) swap(u, v);\n                q(vid[u] + edge, vid[v] + 1);\n     \
    \           break;\n            } else {\n                q(vid[head[v]], vid[v]\
    \ + 1);\n            }\n        }\n    }\n\n    template<typename Query, typename\
    \ MergeFunc, typename T>\n    T query(int u, int v,\n            const Query&\
    \ q, const MergeFunc& f,\n            const T& ident, bool edge = false) const\
    \ {\n        // q(a, b): return f[a, b).\n        // f: \u4E8C\u3064\u306E\u533A\
    \u9593\u306E\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n   \
    \     // ident: \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n        T ret\
    \ = ident;\n        for (;; v = par[head[v]]) {\n            if (depth[head[u]]\
    \ > depth[head[v]]) swap(u, v);\n            if (head[u] == head[v]) {\n     \
    \           if (vid[u] > vid[v]) swap(u, v);\n                return f(ret, q(vid[u]\
    \ + edge, vid[v] + 1));\n            } else {\n                ret = f(ret, q(vid[head[v]],\
    \ vid[v] + 1));\n            }\n        }\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\nstruct HLDecomposition {\n    const vector<vector<int>>&\
    \ G;\n    vector<int> par, size, depth, head, vid;\n    // par[v]: parent of v\n\
    \    // size[v]: size of subtree[v]\n    // depth[v]: depth of v. depth[root]\
    \ = 0\n    // head[v]: head of row containing v\n    // vid[v]: index of v when\
    \ all the rows are aligned.\n\n    void dfs(int v, int p, int d) {\n        par[v]\
    \ = p; depth[v] = d; size[v] = 1;\n        for (int u : G[v]) {\n            if\
    \ (u == p) continue;\n            dfs(u, v, d+1);\n            size[v] += size[u];\n\
    \        }\n    }\n    void hld(int v, int h, int& k) {\n        head[v] = h;\
    \ vid[v] = k++;\n        int ma = 0, id = -1;\n        for (int u : G[v]) {\n\
    \            if (u == par[v]) continue;\n            if (chmax(ma, size[u])) id\
    \ = u;\n        }\n        if (id == -1) return;\n        hld(id, h, k);\n   \
    \     for (int u : G[v]) {\n            if (u == id or u == par[v]) continue;\n\
    \            hld(u, u, k);\n        }\n    }\n\n    HLDecomposition(const vector<vector<int>>&\
    \ g) :\n        G(g), par(g.size()), size(g.size()), depth(g.size()),\n      \
    \  head(g.size()), vid(g.size()) {}\n\n    void build(int root = 0) {\n      \
    \  dfs(root, -1, 0);\n        int k = 0;\n        hld(root, root, k);\n    }\n\
    \n    int lca(int u, int v) const {\n        for (;; v = par[head[v]]) {\n   \
    \         if (depth[head[u]] > depth[head[v]]) swap(u, v);\n            if (head[u]\
    \ == head[v]) {\n                if (depth[u] > depth[v]) swap(u, v);\n      \
    \          return u;\n            }\n        }\n    }\n\n    template<typename\
    \ UpdateQuery>\n    void update(int u, int v, const UpdateQuery& q, bool edge\
    \ = false) const {\n        // q(a, b): update [a, b).\n        for (;; v = par[head[v]])\
    \ {\n            if (depth[head[u]] > depth[head[v]]) swap(u, v);\n          \
    \  if (head[u] == head[v]) {\n                if (vid[u] > vid[v]) swap(u, v);\n\
    \                q(vid[u] + edge, vid[v] + 1);\n                break;\n     \
    \       } else {\n                q(vid[head[v]], vid[v] + 1);\n            }\n\
    \        }\n    }\n\n    template<typename Query, typename MergeFunc, typename\
    \ T>\n    T query(int u, int v,\n            const Query& q, const MergeFunc&\
    \ f,\n            const T& ident, bool edge = false) const {\n        // q(a,\
    \ b): return f[a, b).\n        // f: \u4E8C\u3064\u306E\u533A\u9593\u306E\u8981\
    \u7D20\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n        // ident: \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n        T ret = ident;\n        for\
    \ (;; v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]]) swap(u,\
    \ v);\n            if (head[u] == head[v]) {\n                if (vid[u] > vid[v])\
    \ swap(u, v);\n                return f(ret, q(vid[u] + edge, vid[v] + 1));\n\
    \            } else {\n                ret = f(ret, q(vid[head[v]], vid[v] + 1));\n\
    \            }\n        }\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/tree/hld.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/hld/lca.test.cpp
  - test/tree/hld/hld.test.cpp
documentation_of: lib/tree/hld.cpp
layout: document
redirect_from:
- /library/lib/tree/hld.cpp
- /library/lib/tree/hld.cpp.html
title: lib/tree/hld.cpp
---
