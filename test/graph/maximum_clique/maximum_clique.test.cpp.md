---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/maximum_clique.cpp
    title: lib/graph/maximum_clique.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306
  bundledCode: "#line 1 \"test/graph/maximum_clique/maximum_clique.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306\"\n\n\
    #line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \  }\n\n    return ret;\n}\n#line 4 \"test/graph/maximum_clique/maximum_clique.test.cpp\"\
    \n\nint main()\n{\n    int n, m; cin >> n >> m;\n    vector<vector<bool>> G(n,\
    \ vector<bool>(n));\n    for (int i = 0; i < n; ++i) G[i][i] = true;\n\n    vector<vector<int>>\
    \ g(n, vector<int>(n));\n    for (int i = 0; i < m; ++i) {\n        int u, v,\
    \ f; cin >> u >> v >> f; --u, --v;\n        G[u][v] = G[v][u] = 1;\n        g[u][v]\
    \ = g[v][u] = f;\n    }\n\n    auto f = [&](const vector<int>& vs){\n        int\
    \ ret = 0;\n        for (int i : vs) {\n            int mi = 0;\n            for\
    \ (int j : vs) if (i != j) {\n                if (mi == 0) mi = g[i][j];\n   \
    \             else chmin(mi, g[i][j]);\n            }\n            ret += mi;\n\
    \        }\n        return ret;\n    };\n\n    cout << maximum_clique<int>(G,\
    \ f) << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306\"\
    \n\n#include \"../../../lib/graph/maximum_clique.cpp\"\n\nint main()\n{\n    int\
    \ n, m; cin >> n >> m;\n    vector<vector<bool>> G(n, vector<bool>(n));\n    for\
    \ (int i = 0; i < n; ++i) G[i][i] = true;\n\n    vector<vector<int>> g(n, vector<int>(n));\n\
    \    for (int i = 0; i < m; ++i) {\n        int u, v, f; cin >> u >> v >> f; --u,\
    \ --v;\n        G[u][v] = G[v][u] = 1;\n        g[u][v] = g[v][u] = f;\n    }\n\
    \n    auto f = [&](const vector<int>& vs){\n        int ret = 0;\n        for\
    \ (int i : vs) {\n            int mi = 0;\n            for (int j : vs) if (i\
    \ != j) {\n                if (mi == 0) mi = g[i][j];\n                else chmin(mi,\
    \ g[i][j]);\n            }\n            ret += mi;\n        }\n        return\
    \ ret;\n    };\n\n    cout << maximum_clique<int>(G, f) << endl;\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/graph/maximum_clique.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/maximum_clique/maximum_clique.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/maximum_clique/maximum_clique.test.cpp
layout: document
redirect_from:
- /verify/test/graph/maximum_clique/maximum_clique.test.cpp
- /verify/test/graph/maximum_clique/maximum_clique.test.cpp.html
title: test/graph/maximum_clique/maximum_clique.test.cpp
---