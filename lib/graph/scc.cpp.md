---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/scc/scc.test.cpp
    title: test/graph/scc/scc.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/scc.cpp\"\n\nstruct SCC {\n    int\
    \ n;\n    vector<vector<int>> g, rg, graph;\n    vector<int> ord, used, comp;\n\
    \n    SCC(const vector<vector<int>>& g) :\n            n(g.size()), g(g), rg(n),\
    \ used(n), comp(n, -1)\n    {\n        for (int i = 0; i < n; ++i) {\n       \
    \     for (int to : g[i]) {\n                rg[to].push_back(i);\n          \
    \  }\n        }\n    }\n\n    void build() {\n        for (int i = 0; i < n; ++i)\
    \ dfs(i);\n        reverse(ord.begin(), ord.end());\n        int ptr = 0;\n  \
    \      for (int i : ord) if (comp[i] == -1) rdfs(i, ptr), ptr++;\n\n        graph.resize(ptr);\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int to : g[i]) {\n  \
    \              int x = comp[i], y = comp[to];\n                if (x == y) continue;\n\
    \                graph[x].push_back(y);\n            }\n        }\n        for\
    \ (auto& v : graph) {\n            sort(v.begin(), v.end());\n            v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n        }\n    }\n\nprivate:\n    void dfs(int idx) {\n\
    \        if (used[idx]) return;\n        used[idx] = true;\n        for (int to\
    \ : g[idx]) dfs(to);\n        ord.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (int to : rg[idx]) rdfs(to, cnt);\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\nstruct SCC {\n    int n;\n    vector<vector<int>>\
    \ g, rg, graph;\n    vector<int> ord, used, comp;\n\n    SCC(const vector<vector<int>>&\
    \ g) :\n            n(g.size()), g(g), rg(n), used(n), comp(n, -1)\n    {\n  \
    \      for (int i = 0; i < n; ++i) {\n            for (int to : g[i]) {\n    \
    \            rg[to].push_back(i);\n            }\n        }\n    }\n\n    void\
    \ build() {\n        for (int i = 0; i < n; ++i) dfs(i);\n        reverse(ord.begin(),\
    \ ord.end());\n        int ptr = 0;\n        for (int i : ord) if (comp[i] ==\
    \ -1) rdfs(i, ptr), ptr++;\n\n        graph.resize(ptr);\n        for (int i =\
    \ 0; i < n; ++i) {\n            for (int to : g[i]) {\n                int x =\
    \ comp[i], y = comp[to];\n                if (x == y) continue;\n            \
    \    graph[x].push_back(y);\n            }\n        }\n        for (auto& v :\
    \ graph) {\n            sort(v.begin(), v.end());\n            v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n        }\n    }\n\nprivate:\n    void dfs(int idx) {\n\
    \        if (used[idx]) return;\n        used[idx] = true;\n        for (int to\
    \ : g[idx]) dfs(to);\n        ord.push_back(idx);\n    }\n\n    void rdfs(int\
    \ idx, int cnt) {\n        if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n\
    \        for (int to : rg[idx]) rdfs(to, cnt);\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/scc.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/scc/scc.test.cpp
documentation_of: lib/graph/scc.cpp
layout: document
redirect_from:
- /library/lib/graph/scc.cpp
- /library/lib/graph/scc.cpp.html
title: lib/graph/scc.cpp
---