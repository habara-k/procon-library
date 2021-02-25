---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/lca.cpp
    title: lib/tree/lca.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/tree/lca/lca.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/tree/lca.cpp\"\n\nstruct LCA {\n    int\
    \ n, log2_n;\n    vector<int> depth;\n    vector<vector<int>> par;\n\n    void\
    \ dfs(const vector<vector<int>>& G, int v, int p, int d) {\n        depth[v] =\
    \ d;\n        par[0][v] = p;\n        for (auto to : G[v]) {\n            if (to\
    \ != p) dfs(G, to, v, d+1);\n        }\n    }\n\n    LCA(const vector<vector<int>>&\
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
    \     return par[0][u];\n    }\n};\n#line 4 \"test/tree/lca/lca.test.cpp\"\n\n\
    int main() {\n    int N, Q;\n    cin >> N;\n    vector<vector<int>> g(N);\n  \
    \  for (int i = 0; i < N; ++i) {\n        int k; cin >> k;\n        while (k--)\
    \ {\n            int c; cin >> c;\n            g[i].push_back(c);\n        }\n\
    \    }\n\n    LCA lca(g);\n    cin >> Q;\n    while (Q--) {\n        int x, y;\
    \ cin >> x >> y;\n        cout << lca.query(x, y) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include \"../../../lib/tree/lca.cpp\"\n\nint main() {\n    int N, Q;\n  \
    \  cin >> N;\n    vector<vector<int>> g(N);\n    for (int i = 0; i < N; ++i) {\n\
    \        int k; cin >> k;\n        while (k--) {\n            int c; cin >> c;\n\
    \            g[i].push_back(c);\n        }\n    }\n\n    LCA lca(g);\n    cin\
    \ >> Q;\n    while (Q--) {\n        int x, y; cin >> x >> y;\n        cout <<\
    \ lca.query(x, y) << endl;\n    }\n}\n"
  dependsOn:
  - lib/tree/lca.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/tree/lca/lca.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/lca/lca.test.cpp
layout: document
redirect_from:
- /verify/test/tree/lca/lca.test.cpp
- /verify/test/tree/lca/lca.test.cpp.html
title: test/tree/lca/lca.test.cpp
---
