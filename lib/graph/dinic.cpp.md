---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dinic/dinic.test.cpp
    title: test/graph/dinic/dinic.test.cpp
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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/dinic.cpp\"\n\ntemplate<typename T>\n\
    struct Dinic {\n    // O(EV^2)\n    struct edge {\n        int to, rev;\n    \
    \    T cap;\n        edge(int to, T cap, int rev) :\n            to(to), cap(cap),\
    \ rev(rev) {}\n    };\n\n    vector<vector<edge>> g;\n    vector<int> level, iter;\n\
    \    const T INF;\n\n    Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}\n\
    \n    void add_edge(int s, int t, T cap) {\n        g[s].emplace_back(t, cap,\
    \ (int)g[t].size());\n        g[t].emplace_back(s,   0, (int)g[s].size() - 1);\n\
    \    }\n\n    bool bfs(int s, int t) {\n        level.assign(g.size(), -1);\n\
    \        queue<int> que;\n        level[s] = 0;\n        que.push(s);\n      \
    \  while (!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            for (auto &e : g[v]) {\n                if (e.cap > 0 and level[e.to]\
    \ == -1) {\n                    level[e.to] = level[v] + 1;\n                \
    \    que.push(e.to);\n                }\n            }\n        }\n        return\
    \ level[t] != -1;\n    }\n\n    T dfs(int v, const int t, T flow) {\n        if\
    \ (v == t) return flow;\n        for (int &i = iter[v]; i < g[v].size(); ++i)\
    \ {\n            edge &e = g[v][i];\n            if (e.cap > 0 and level[v] <\
    \ level[e.to]) {\n                T d = dfs(e.to, t, min(flow, e.cap));\n    \
    \            if (d > 0) {\n                    e.cap -= d;\n                 \
    \   g[e.to][e.rev].cap += d;\n                    return d;\n                }\n\
    \            }\n        }\n        return 0;\n    }\n\n    T max_flow(int s, int\
    \ t) {\n        T flow = 0;\n        while (bfs(s, t)) {\n            iter.assign(g.size(),\
    \ 0);\n            T f = 0;\n            while ((f = dfs(s, t, INF)) > 0) flow\
    \ += f;\n        }\n        return flow;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename T>\nstruct Dinic {\n  \
    \  // O(EV^2)\n    struct edge {\n        int to, rev;\n        T cap;\n     \
    \   edge(int to, T cap, int rev) :\n            to(to), cap(cap), rev(rev) {}\n\
    \    };\n\n    vector<vector<edge>> g;\n    vector<int> level, iter;\n    const\
    \ T INF;\n\n    Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}\n\n    void\
    \ add_edge(int s, int t, T cap) {\n        g[s].emplace_back(t, cap, (int)g[t].size());\n\
    \        g[t].emplace_back(s,   0, (int)g[s].size() - 1);\n    }\n\n    bool bfs(int\
    \ s, int t) {\n        level.assign(g.size(), -1);\n        queue<int> que;\n\
    \        level[s] = 0;\n        que.push(s);\n        while (!que.empty()) {\n\
    \            int v = que.front();\n            que.pop();\n            for (auto\
    \ &e : g[v]) {\n                if (e.cap > 0 and level[e.to] == -1) {\n     \
    \               level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return level[t] != -1;\n\
    \    }\n\n    T dfs(int v, const int t, T flow) {\n        if (v == t) return\
    \ flow;\n        for (int &i = iter[v]; i < g[v].size(); ++i) {\n            edge\
    \ &e = g[v][i];\n            if (e.cap > 0 and level[v] < level[e.to]) {\n   \
    \             T d = dfs(e.to, t, min(flow, e.cap));\n                if (d > 0)\
    \ {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n\n    T max_flow(int s, int t) {\n        T flow\
    \ = 0;\n        while (bfs(s, t)) {\n            iter.assign(g.size(), 0);\n \
    \           T f = 0;\n            while ((f = dfs(s, t, INF)) > 0) flow += f;\n\
    \        }\n        return flow;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/dinic.cpp
  requiredBy: []
  timestamp: '2020-04-20 20:05:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dinic/dinic.test.cpp
documentation_of: lib/graph/dinic.cpp
layout: document
redirect_from:
- /library/lib/graph/dinic.cpp
- /library/lib/graph/dinic.cpp.html
title: lib/graph/dinic.cpp
---
