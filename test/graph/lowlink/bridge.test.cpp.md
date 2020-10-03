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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B
  bundledCode: "#line 1 \"test/graph/lowlink/bridge.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n// type {{{\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld\
    \ = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\nusing vll\
    \ = vector<ll>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<ll>>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/lowlink.cpp\"\n\nstruct LowLink {\n \
    \   // require: undirected simple graph\n    vector<vector<int>> g;\n    const\
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
    \ ord[v] < low[u];\n    }\n};\n#line 4 \"test/graph/lowlink/bridge.test.cpp\"\n\
    \nint main()\n{\n    int V, E; cin >> V >> E;\n    vector<vector<int>> G(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int s, t; cin >> s >> t;\n       \
    \ G[s].push_back(t);\n        G[t].push_back(s);\n    }\n    LowLink lowlink(G);\n\
    \n    lowlink.build();\n\n    sort(lowlink.bridges.begin(), lowlink.bridges.end());\n\
    \    for (const auto& p : lowlink.bridges) {\n        printf(\"%d %d\\n\", p.first,\
    \ p.second);\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B\"\
    \n\n#include \"../../../lib/graph/lowlink.cpp\"\n\nint main()\n{\n    int V, E;\
    \ cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int i = 0; i < E; ++i)\
    \ {\n        int s, t; cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink lowlink(G);\n\n    lowlink.build();\n\n    sort(lowlink.bridges.begin(),\
    \ lowlink.bridges.end());\n    for (const auto& p : lowlink.bridges) {\n     \
    \   printf(\"%d %d\\n\", p.first, p.second);\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - lib/graph/lowlink.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/lowlink/bridge.test.cpp
  requiredBy: []
  timestamp: '2020-04-20 20:05:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink/bridge.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink/bridge.test.cpp
- /verify/test/graph/lowlink/bridge.test.cpp.html
title: test/graph/lowlink/bridge.test.cpp
---
