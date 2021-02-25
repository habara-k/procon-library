---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/centroid.cpp
    title: lib/tree/centroid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/tree_hash/tree_hash.test.cpp
    title: test/tree/tree_hash/tree_hash.test.cpp
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/tree/centroid.cpp\"\n\nvector<int> centroid(const\
    \ vector<vector<int>>& g) {\n    const int n = g.size();\n    vector<int> sz(n,1),\
    \ ret;\n    function<int(int,int)> dfs = [&](int u,int p) {\n        bool isCent\
    \ = true;\n        for (int v : g[u]) {\n            if (v == p) continue;\n \
    \           sz[u] += dfs(v, u);\n            if (sz[v] > n / 2) isCent = false;\n\
    \        }\n        if (n - sz[u] > n / 2) isCent = false;\n        if (isCent)\
    \ ret.emplace_back(u);\n        return sz[u];\n    };\n    dfs(0, -1);\n    return\
    \ ret;\n}\n#line 3 \"lib/tree/tree_hash.cpp\"\n\nstruct TreeHash {\n    using\
    \ u64 = uint64_t;\n    using i128 = __int128_t;\n\n    TreeHash(const vector<vector<int>>&\
    \ g, int seed=0) : g(g) {\n        int n = g.size();\n        mt19937 random(seed);\n\
    \        uniform_int_distribution<u64> dist(2, MOD-2);\n        for (int i = 0;\
    \ i < n; ++i) base.emplace_back(dist(random));\n    }\n\n    u64 get() {\n   \
    \     vector<u64> hash;\n        for (int root : centroid(g)) {\n            hash.emplace_back(dfs(root,\
    \ -1, 0));\n        }\n        return *min_element(hash.begin(), hash.end());\n\
    \    }\n\nprivate:\n    vector<u64> base;\n    vector<vector<int>> g;\n    static\
    \ const u64 MOD = (1ul << 61) - 1;\n\n    static u64 mul(i128 a, i128 b) {\n \
    \       i128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n        if (t >=\
    \ MOD) t -= MOD;\n        return t;\n    }\n\n    u64 dfs(int u, int p, int d)\
    \ {\n        u64 hash = 1;\n        for (int v : g[u]) {\n            if (v ==\
    \ p) continue;\n            hash = mul(hash, dfs(v, u, d+1));\n        }\n   \
    \     hash += base[d];\n        return hash >= MOD ? hash - MOD : hash;\n    }\n\
    };\n"
  code: "#include \"../template.cpp\"\n#include \"centroid.cpp\"\n\nstruct TreeHash\
    \ {\n    using u64 = uint64_t;\n    using i128 = __int128_t;\n\n    TreeHash(const\
    \ vector<vector<int>>& g, int seed=0) : g(g) {\n        int n = g.size();\n  \
    \      mt19937 random(seed);\n        uniform_int_distribution<u64> dist(2, MOD-2);\n\
    \        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));\n    }\n\
    \n    u64 get() {\n        vector<u64> hash;\n        for (int root : centroid(g))\
    \ {\n            hash.emplace_back(dfs(root, -1, 0));\n        }\n        return\
    \ *min_element(hash.begin(), hash.end());\n    }\n\nprivate:\n    vector<u64>\
    \ base;\n    vector<vector<int>> g;\n    static const u64 MOD = (1ul << 61) -\
    \ 1;\n\n    static u64 mul(i128 a, i128 b) {\n        i128 t = a * b;\n      \
    \  t = (t >> 61) + (t & MOD);\n        if (t >= MOD) t -= MOD;\n        return\
    \ t;\n    }\n\n    u64 dfs(int u, int p, int d) {\n        u64 hash = 1;\n   \
    \     for (int v : g[u]) {\n            if (v == p) continue;\n            hash\
    \ = mul(hash, dfs(v, u, d+1));\n        }\n        hash += base[d];\n        return\
    \ hash >= MOD ? hash - MOD : hash;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  - lib/tree/centroid.cpp
  isVerificationFile: false
  path: lib/tree/tree_hash.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/tree_hash/tree_hash.test.cpp
documentation_of: lib/tree/tree_hash.cpp
layout: document
redirect_from:
- /library/lib/tree/tree_hash.cpp
- /library/lib/tree/tree_hash.cpp.html
title: lib/tree/tree_hash.cpp
---
