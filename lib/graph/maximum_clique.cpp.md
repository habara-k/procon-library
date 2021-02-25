---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/maximum_clique/maximum_clique.test.cpp
    title: test/graph/maximum_clique/maximum_clique.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/maximum_clique.cpp\"\n\ntemplate<typename\
    \ T>\nT maximum_clique(\n        vector<vector<bool>> G,\n        const function<T(const\
    \ vector<int>&)>& f) {\n\n    // O(2^sqrt(2M) N) ?\n\n    // G: undirected graph\
    \ (matrix)\n    // f: return max(f(clique set))\n\n    T ret = numeric_limits<T>::min();\n\
    \n    int n = G.size();\n    vector<int> deg(n);\n    int M = 0;  // |edge|\n\
    \    for (int i = 0; i < n; ++i) {\n        for (int j = i+1; j < n; ++j) {\n\
    \            if (G[i][j]) ++deg[i], ++deg[j], ++M;\n        }\n    }\n    vector<bool>\
    \ used(n);\n\n    int lim = sqrt(2*M);\n\n    while (true) {\n        int u =\
    \ -1;\n        for (int i = 0; i < n; ++i) {\n            if (!used[i] and deg[i]\
    \ < lim) {\n                u = i;\n                used[u] = true;\n        \
    \        break;\n            }\n        }\n\n        vector<int> neighbor;\n \
    \       if (u != -1) neighbor.push_back(u);\n        for (int v = 0; v < n; ++v)\
    \ if (!used[v]) {\n            if (u == -1 or G[u][v]) {\n                neighbor.push_back(v);\n\
    \            }\n        }\n\n        int sz = neighbor.size();\n        vector<int>\
    \ bit(sz);\n        for (int i = 0; i < sz; ++i) {\n            for (int j = 0;\
    \ j < sz; ++j) {\n                if (G[neighbor[i]][neighbor[j]]) {\n       \
    \             bit[i] |= 1 << j;\n                }\n            }\n        }\n\
    \n        vector<bool> dp(1<<sz);\n        dp[0] = true;\n        for (int s =\
    \ 1; s < 1<<sz; ++s) {\n            int i = __builtin_ffs(s) - 1;\n          \
    \  dp[s] = dp[s & ~(1<<i)] and (~bit[i] & s) == 0;\n            if (dp[s]) {\n\
    \                vector<int> vs;\n                for (int i = 0; i < sz; ++i)\
    \ if (s >> i & 1) {\n                    vs.push_back(neighbor[i]);\n        \
    \        }\n                ret = max(ret, f(vs));\n            }\n        }\n\
    \n        if (u == -1) break;\n\n        for (int v : neighbor) {\n          \
    \  --deg[v], --deg[u];\n            G[u][v] = G[v][u] = false;\n        }\n  \
    \  }\n\n    return ret;\n}\n"
  code: "#include \"../template.cpp\"\n\ntemplate<typename T>\nT maximum_clique(\n\
    \        vector<vector<bool>> G,\n        const function<T(const vector<int>&)>&\
    \ f) {\n\n    // O(2^sqrt(2M) N) ?\n\n    // G: undirected graph (matrix)\n  \
    \  // f: return max(f(clique set))\n\n    T ret = numeric_limits<T>::min();\n\n\
    \    int n = G.size();\n    vector<int> deg(n);\n    int M = 0;  // |edge|\n \
    \   for (int i = 0; i < n; ++i) {\n        for (int j = i+1; j < n; ++j) {\n \
    \           if (G[i][j]) ++deg[i], ++deg[j], ++M;\n        }\n    }\n    vector<bool>\
    \ used(n);\n\n    int lim = sqrt(2*M);\n\n    while (true) {\n        int u =\
    \ -1;\n        for (int i = 0; i < n; ++i) {\n            if (!used[i] and deg[i]\
    \ < lim) {\n                u = i;\n                used[u] = true;\n        \
    \        break;\n            }\n        }\n\n        vector<int> neighbor;\n \
    \       if (u != -1) neighbor.push_back(u);\n        for (int v = 0; v < n; ++v)\
    \ if (!used[v]) {\n            if (u == -1 or G[u][v]) {\n                neighbor.push_back(v);\n\
    \            }\n        }\n\n        int sz = neighbor.size();\n        vector<int>\
    \ bit(sz);\n        for (int i = 0; i < sz; ++i) {\n            for (int j = 0;\
    \ j < sz; ++j) {\n                if (G[neighbor[i]][neighbor[j]]) {\n       \
    \             bit[i] |= 1 << j;\n                }\n            }\n        }\n\
    \n        vector<bool> dp(1<<sz);\n        dp[0] = true;\n        for (int s =\
    \ 1; s < 1<<sz; ++s) {\n            int i = __builtin_ffs(s) - 1;\n          \
    \  dp[s] = dp[s & ~(1<<i)] and (~bit[i] & s) == 0;\n            if (dp[s]) {\n\
    \                vector<int> vs;\n                for (int i = 0; i < sz; ++i)\
    \ if (s >> i & 1) {\n                    vs.push_back(neighbor[i]);\n        \
    \        }\n                ret = max(ret, f(vs));\n            }\n        }\n\
    \n        if (u == -1) break;\n\n        for (int v : neighbor) {\n          \
    \  --deg[v], --deg[u];\n            G[u][v] = G[v][u] = false;\n        }\n  \
    \  }\n\n    return ret;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/maximum_clique.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/maximum_clique/maximum_clique.test.cpp
documentation_of: lib/graph/maximum_clique.cpp
layout: document
redirect_from:
- /library/lib/graph/maximum_clique.cpp
- /library/lib/graph/maximum_clique.cpp.html
title: lib/graph/maximum_clique.cpp
---
