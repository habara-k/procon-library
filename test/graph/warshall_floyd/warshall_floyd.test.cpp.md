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
    \ 1e-9;\n// }}}\n\n\n#line 2 \"lib/graph/warshall_floyd.cpp\"\n\ntemplate<typename\
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
    \    for (int i = 0; i < V; ++i) {\n        if (G[i][i] < 0) {\n            puts(\"\
    NEGATIVE CYCLE\");\n            return 0;\n        }\n    }\n    for (int i =\
    \ 0; i < V; ++i) {\n        for (int j = 0; j < V; ++j) {\n            if (j >\
    \ 0) putchar(' ');\n            if (G[i][j] == INF) printf(\"INF\");\n       \
    \     else printf(\"%d\", G[i][j]);\n        }\n        putchar('\\n');\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../../../lib/graph/warshall_floyd.cpp\"\n\nint main() {\n    int\
    \ V, E;\n    cin >> V >> E;\n\n    const int INF = numeric_limits<int>::max();\n\
    \    vector<vector<int>> G(V, vector<int>(V, INF));\n    for (int i = 0; i < V;\
    \ ++i) G[i][i] = 0;\n    for (int i = 0; i < E; ++i) {\n        int x, y, z;\n\
    \        cin >> x >> y >> z;\n        G[x][y] = z;\n    }\n\n    warshall_floyd(G);\n\
    \    for (int i = 0; i < V; ++i) {\n        if (G[i][i] < 0) {\n            puts(\"\
    NEGATIVE CYCLE\");\n            return 0;\n        }\n    }\n    for (int i =\
    \ 0; i < V; ++i) {\n        for (int j = 0; j < V; ++j) {\n            if (j >\
    \ 0) putchar(' ');\n            if (G[i][j] == INF) printf(\"INF\");\n       \
    \     else printf(\"%d\", G[i][j]);\n        }\n        putchar('\\n');\n    }\n\
    }\n"
  dependsOn:
  - lib/graph/warshall_floyd.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/warshall_floyd/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2020-04-23 00:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/warshall_floyd/warshall_floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/warshall_floyd/warshall_floyd.test.cpp
- /verify/test/graph/warshall_floyd/warshall_floyd.test.cpp.html
title: test/graph/warshall_floyd/warshall_floyd.test.cpp
---
