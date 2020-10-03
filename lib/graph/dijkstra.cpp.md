---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/edge.cpp
    title: lib/graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra/dijkstra.test.cpp
    title: test/graph/dijkstra/dijkstra.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 1 \"lib/graph/edge.cpp\"\n\n\n#line 4 \"lib/graph/edge.cpp\"\
    \n\ntemplate<typename T>\nstruct edge {\n    int src, to;\n    T cost;\n\n   \
    \ friend ostream& operator<<(ostream& os, const edge& e) {\n        return os\
    \ << \"(\" << e.src << \"->\" << e.to << \":\" << e.cost << \")\";\n    }\n};\n\
    \ntemplate<typename T>\nusing Graph = vector<vector<edge<T>>>;\n\n\n#line 3 \"\
    lib/graph/dijkstra.cpp\"\n\ntemplate<typename T>\nvector<T> dijkstra(const Graph<T>&\
    \ g, int s) {\n    const T infty = numeric_limits<T>::max();\n    vector<T> d(g.size(),\
    \ infty);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi, vector<Pi>,\
    \ greater<Pi>> que;\n    d[s] = 0;\n    que.emplace(d[s], s);\n    while (!que.empty())\
    \ {\n        auto [cost, v] = que.top();\n        que.pop();\n        if (d[v]\
    \ < cost) continue;\n        for (const auto &e : g[v]) {\n            if (T alt\
    \ = cost + e.cost; d[e.to] > alt) {\n                d[e.to] = alt;\n        \
    \        que.emplace(alt, e.to);\n            }\n        }\n    }\n    return\
    \ d;\n}\n"
  code: "#include \"../template.cpp\"\n#include \"./edge.cpp\"\n\ntemplate<typename\
    \ T>\nvector<T> dijkstra(const Graph<T>& g, int s) {\n    const T infty = numeric_limits<T>::max();\n\
    \    vector<T> d(g.size(), infty);\n\n    using Pi = pair<T, int>;\n    priority_queue<Pi,\
    \ vector<Pi>, greater<Pi>> que;\n    d[s] = 0;\n    que.emplace(d[s], s);\n  \
    \  while (!que.empty()) {\n        auto [cost, v] = que.top();\n        que.pop();\n\
    \        if (d[v] < cost) continue;\n        for (const auto &e : g[v]) {\n  \
    \          if (T alt = cost + e.cost; d[e.to] > alt) {\n                d[e.to]\
    \ = alt;\n                que.emplace(alt, e.to);\n            }\n        }\n\
    \    }\n    return d;\n}\n"
  dependsOn:
  - lib/template.cpp
  - lib/graph/edge.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-06-26 12:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra/dijkstra.test.cpp
documentation_of: lib/graph/dijkstra.cpp
layout: document
redirect_from:
- /library/lib/graph/dijkstra.cpp
- /library/lib/graph/dijkstra.cpp.html
title: lib/graph/dijkstra.cpp
---
