---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/heavy_light_decomposition.cpp
    title: lib/graph/heavy_light_decomposition.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/graph/heavy_light_decomposition/lca.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing\
    \ vll = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/heavy_light_decomposition.cpp\"\n\nstruct\
    \ HLDecomposition {\n    const vector<vector<int>>& G;\n    vector<int> par, size,\
    \ depth, head, vid;\n    // par[v]: parent of v\n    // size[v]: size of subtree[v]\n\
    \    // depth[v]: depth of v. depth[root] = 0\n    // head[v]: head of row containing\
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
    \ vid[v] + 1));\n            }\n        }\n    }\n};\n#line 4 \"test/graph/heavy_light_decomposition/lca.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N;\n    vector<vector<int>> g(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        int k; cin >> k;\n        while (k--)\
    \ {\n            int c; cin >> c;\n            g[i].push_back(c);\n        }\n\
    \    }\n\n    HLDecomposition hld(g);\n    hld.build(0);\n\n    cin >> Q;\n  \
    \  while (Q--) {\n        int x, y; cin >> x >> y;\n        printf(\"%d\\n\",\
    \ hld.lca(x, y));\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include \"../../../lib/graph/heavy_light_decomposition.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N;\n    vector<vector<int>> g(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        int k; cin >> k;\n        while (k--) {\n    \
    \        int c; cin >> c;\n            g[i].push_back(c);\n        }\n    }\n\n\
    \    HLDecomposition hld(g);\n    hld.build(0);\n\n    cin >> Q;\n    while (Q--)\
    \ {\n        int x, y; cin >> x >> y;\n        printf(\"%d\\n\", hld.lca(x, y));\n\
    \    }\n}\n"
  dependsOn:
  - lib/graph/heavy_light_decomposition.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/heavy_light_decomposition/lca.test.cpp
  requiredBy: []
  timestamp: '2020-04-20 20:05:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/heavy_light_decomposition/lca.test.cpp
layout: document
redirect_from:
- /verify/test/graph/heavy_light_decomposition/lca.test.cpp
- /verify/test/graph/heavy_light_decomposition/lca.test.cpp.html
title: test/graph/heavy_light_decomposition/lca.test.cpp
---
