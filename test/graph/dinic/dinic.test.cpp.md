---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dinic.cpp
    title: lib/graph/dinic.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/graph/dinic/dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/dinic.cpp\"\n\ntemplate<typename\
    \ T>\nstruct Dinic {\n    // O(EV^2)\n    struct edge {\n        int to, rev;\n\
    \        T cap;\n        edge(int to, T cap, int rev) :\n            to(to), cap(cap),\
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
    \ += f;\n        }\n        return flow;\n    }\n};\n#line 4 \"test/graph/dinic/dinic.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    Dinic<int> g(V);\n  \
    \  for (int i = 0; i < E; ++i) {\n        int a, b, c;\n        cin >> a >> b\
    \ >> c;\n        g.add_edge(a, b, c);\n    }\n    cout << g.max_flow(0, V-1) <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"../../../lib/graph/dinic.cpp\"\n\nint main() {\n    int V, E;\n\
    \    cin >> V >> E;\n    Dinic<int> g(V);\n    for (int i = 0; i < E; ++i) {\n\
    \        int a, b, c;\n        cin >> a >> b >> c;\n        g.add_edge(a, b, c);\n\
    \    }\n    cout << g.max_flow(0, V-1) << endl;\n}\n"
  dependsOn:
  - lib/graph/dinic.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/dinic/dinic.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dinic/dinic.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dinic/dinic.test.cpp
- /verify/test/graph/dinic/dinic.test.cpp.html
title: test/graph/dinic/dinic.test.cpp
---
