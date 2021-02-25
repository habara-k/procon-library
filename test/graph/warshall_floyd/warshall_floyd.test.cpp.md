---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/warshall_floyd.cpp
    title: lib/graph/warshall_floyd.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"test/graph/warshall_floyd/warshall_floyd.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/warshall_floyd.cpp\"\n\ntemplate<typename\
    \ T>\nvoid warshall_floyd(vector<vector<T>> &g) {\n    const T INF = numeric_limits<T>::max();\n\
    \    int n = g.size();\n    for (int k = 0; k < n; ++k) {\n        for (int i\
    \ = 0; i < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n            \
    \    if (g[i][k] == INF or g[k][j] == INF) continue;\n                g[i][j]\
    \ = min(g[i][j], g[i][k] + g[k][j]);\n            }\n        }\n    }\n}\n#line\
    \ 4 \"test/graph/warshall_floyd/warshall_floyd.test.cpp\"\n\nint main() {\n  \
    \  int V, E;\n    cin >> V >> E;\n\n    const int INF = numeric_limits<int>::max();\n\
    \    vector<vector<int>> G(V, vector<int>(V, INF));\n    for (int i = 0; i < V;\
    \ ++i) G[i][i] = 0;\n    for (int i = 0; i < E; ++i) {\n        int x, y, z;\n\
    \        cin >> x >> y >> z;\n        G[x][y] = z;\n    }\n\n    warshall_floyd(G);\n\
    \    for (int i = 0; i < V; ++i) {\n        if (G[i][i] < 0) {\n            cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n        }\n    }\n  \
    \  for (int i = 0; i < V; ++i) {\n        for (int j = 0; j < V; ++j) {\n    \
    \        if (j) cout << ' ';\n            if (G[i][j] == INF) cout << \"INF\"\
    ;\n            else cout << G[i][j];\n        }\n        cout << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../../../lib/graph/warshall_floyd.cpp\"\n\nint main() {\n    int\
    \ V, E;\n    cin >> V >> E;\n\n    const int INF = numeric_limits<int>::max();\n\
    \    vector<vector<int>> G(V, vector<int>(V, INF));\n    for (int i = 0; i < V;\
    \ ++i) G[i][i] = 0;\n    for (int i = 0; i < E; ++i) {\n        int x, y, z;\n\
    \        cin >> x >> y >> z;\n        G[x][y] = z;\n    }\n\n    warshall_floyd(G);\n\
    \    for (int i = 0; i < V; ++i) {\n        if (G[i][i] < 0) {\n            cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n        }\n    }\n  \
    \  for (int i = 0; i < V; ++i) {\n        for (int j = 0; j < V; ++j) {\n    \
    \        if (j) cout << ' ';\n            if (G[i][j] == INF) cout << \"INF\"\
    ;\n            else cout << G[i][j];\n        }\n        cout << endl;\n    }\n\
    }\n"
  dependsOn:
  - lib/graph/warshall_floyd.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/warshall_floyd/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/warshall_floyd/warshall_floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/warshall_floyd/warshall_floyd.test.cpp
- /verify/test/graph/warshall_floyd/warshall_floyd.test.cpp.html
title: test/graph/warshall_floyd/warshall_floyd.test.cpp
---