---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.cpp
    title: lib/graph/lowlink.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A
  bundledCode: "#line 1 \"test/graph/lowlink/articulation.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/lowlink.cpp\"\n\nstruct LowLink {\n\
    \    // require: undirected simple graph\n    vector<vector<int>> g;\n    const\
    \ int sz;\n    vector<int> ord, low, par;\n    vector<int> used, _is_articulation;\n\
    \    vector<int> articulations;\n    vector<pair<int,int>> bridges;\n\n    LowLink(const\
    \ vector<vector<int>>& g) :\n        g(g), sz(g.size()), ord(sz), low(sz), used(sz),\n\
    \        par(sz), _is_articulation(sz) {}\n\n    void build() {\n        int k\
    \ = 0;\n        for (int i = 0; i < sz; ++i) {\n            if (!used[i]) dfs(i,\
    \ -1, k);\n        }\n    }\n\n    void dfs(int v, int p, int& k) {\n        used[v]\
    \ = 1;\n        par[v] = p;\n        low[v] = ord[v] = k++;\n        int cnt =\
    \ 0;\n        for (int to : g[v]) {\n            if (!used[to]) {\n          \
    \      ++cnt;\n                dfs(to, v, k);\n                low[v] = min(low[v],\
    \ low[to]);\n                _is_articulation[v] |= ord[v] <= low[to];\n     \
    \           if (ord[v] < low[to]) {\n                    bridges.emplace_back(minmax(to,\
    \ v));\n                }\n            } else if (to != p) {\n               \
    \ low[v] = min(low[v], ord[to]);\n            }\n        }\n        if (p == -1)\
    \ _is_articulation[v] = cnt > 1;\n        if (_is_articulation[v]) articulations.push_back(v);\n\
    \    }\n\n    bool is_articulation(int v) const { return _is_articulation[v];\
    \ }\n    bool is_bridge(int u, int v) const {\n        if (u != par[v] and v !=\
    \ par[u]) return false;\n        if (u == par[v]) swap(u, v);\n        return\
    \ ord[v] < low[u];\n    }\n};\n#line 4 \"test/graph/lowlink/articulation.test.cpp\"\
    \n\nint main()\n{\n    int V, E; cin >> V >> E;\n    vector<vector<int>> G(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int s, t; cin >> s >> t;\n       \
    \ G[s].push_back(t);\n        G[t].push_back(s);\n    }\n    LowLink lowlink(G);\n\
    \n    lowlink.build();\n\n    sort(lowlink.articulations.begin(), lowlink.articulations.end());\n\
    \    for (int v : lowlink.articulations) {\n        cout << v << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A\"\
    \n\n#include \"../../../lib/graph/lowlink.cpp\"\n\nint main()\n{\n    int V, E;\
    \ cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int i = 0; i < E; ++i)\
    \ {\n        int s, t; cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink lowlink(G);\n\n    lowlink.build();\n\n    sort(lowlink.articulations.begin(),\
    \ lowlink.articulations.end());\n    for (int v : lowlink.articulations) {\n \
    \       cout << v << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/lowlink.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/lowlink/articulation.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink/articulation.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink/articulation.test.cpp
- /verify/test/graph/lowlink/articulation.test.cpp.html
title: test/graph/lowlink/articulation.test.cpp
---
