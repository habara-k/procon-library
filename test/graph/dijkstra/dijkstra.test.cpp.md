---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.cpp
    title: lib/graph/dijkstra.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra/dijkstra.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\n\n#line\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/dijkstra.cpp\"\n\ntemplate<typename\
    \ T>\nvector<T> dijkstra(const vector<vector<edge<T>>>& g, int s) {\n    const\
    \ T inf = numeric_limits<T>::max();\n    vector<T> d(g.size(), inf);\n\n    using\
    \ P = pair<T, int>;\n    priority_queue<P, vector<P>, greater<P>> que;\n    d[s]\
    \ = 0;\n    que.emplace(d[s], s);\n    while (!que.empty()) {\n        auto [cost,\
    \ v] = que.top();\n        que.pop();\n        if (d[v] < cost) continue;\n  \
    \      for (const auto &e : g[v]) {\n            if (T alt = cost + e.cost; d[e.to]\
    \ > alt) {\n                d[e.to] = alt;\n                que.emplace(alt, e.to);\n\
    \            }\n        }\n    }\n    return d;\n}\n#line 4 \"test/graph/dijkstra/dijkstra.test.cpp\"\
    \n\nint main() {\n    int V, E, R;\n    cin >> V >> E >> R;\n    vector<vector<edge<int>>>\
    \ g(V);\n    for (int i = 0; i < E; ++i) {\n        int a, b, c;\n        cin\
    \ >> a >> b >> c;\n        g[a].emplace_back(b, c);\n    }\n\n    for (auto &dist\
    \ : dijkstra(g, R)) {\n        if (dist == numeric_limits<int>::max()) cout <<\
    \ \"INF\" << endl;\n        else cout << dist << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../../../lib/graph/dijkstra.cpp\"\n\nint main() {\n    int V, E,\
    \ R;\n    cin >> V >> E >> R;\n    vector<vector<edge<int>>> g(V);\n    for (int\
    \ i = 0; i < E; ++i) {\n        int a, b, c;\n        cin >> a >> b >> c;\n  \
    \      g[a].emplace_back(b, c);\n    }\n\n    for (auto &dist : dijkstra(g, R))\
    \ {\n        if (dist == numeric_limits<int>::max()) cout << \"INF\" << endl;\n\
    \        else cout << dist << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/dijkstra.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/dijkstra/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra/dijkstra.test.cpp
- /verify/test/graph/dijkstra/dijkstra.test.cpp.html
title: test/graph/dijkstra/dijkstra.test.cpp
---
