---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/union_find.cpp
    title: lib/structure/union_find.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/centroid.cpp
    title: lib/tree/centroid.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/tree_hash.cpp
    title: lib/tree/tree_hash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
  bundledCode: "#line 1 \"test/tree/tree_hash/tree_hash.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\n\n#line 1\
    \ \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n#define\
    \ DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios() {\n\
    \        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n      \
    \  cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll = long\
    \ long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a = b;\
    \ return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a, T\
    \ b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
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
    };\n#line 2 \"lib/structure/union_find.cpp\"\n\nstruct UnionFind\n{\n    const\
    \ int n;\n    vector<int> par, sz;\n    UnionFind(int n) : n(n), par(n), sz(n,\
    \ 1) {\n        for (int i = 0; i < n; ++i) par[i] = i;\n    }\n\n    int root(int\
    \ x) {\n        if (par[x] == x) return x;\n        return par[x] = root(par[x]);\n\
    \    }\n\n    void merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return;\n        if (sz[x] < sz[y]) swap(x, y);\n       \
    \ par[y] = x;\n        sz[x] += sz[y];\n        sz[y] = 0;\n    }\n\n    bool\
    \ issame(int x, int y) {\n        return root(x) == root(y);\n    }\n\n    int\
    \ size(int x) {\n        return sz[root(x)];\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, UnionFind& uf) {\n        os << \"[\";\n        for (int i = 0; i < uf.n;\
    \ ++i) {\n            if (i > 0) os << \" \";\n            os << uf.root(i);\n\
    \        }\n        return os << \"]\" << endl;\n    }\n};\n#line 5 \"test/tree/tree_hash/tree_hash.test.cpp\"\
    \n\nint main() {\n    int n1, m1; cin >> n1 >> m1;\n    vector<vector<int>> g1(n1);\n\
    \    UnionFind uf(n1);\n    REP(i, m1) {\n        int u, v; cin >> u >> v; --u,\
    \ --v;\n        g1[u].emplace_back(v);\n        g1[v].emplace_back(u);\n     \
    \   uf.merge(u, v);\n    }\n    int n2; cin >> n2;\n    vector<vector<int>> g2(n2);\n\
    \    REP(i, n2-1) {\n        int u, v; cin >> u >> v; --u, --v;\n        g2[u].emplace_back(v);\n\
    \        g2[v].emplace_back(u);\n    }\n\n    vector<int> roots;\n    for (int\
    \ i = 0; i < n1; ++i) if (uf.root(i) == i) roots.emplace_back(i);\n\n    map<int,map<int,int>>\
    \ ord;\n    for (int i = 0; i < n1; ++i) {\n        ord[uf.root(i)][i] = -1;\n\
    \    }\n\n    map<int,vector<vector<int>>> g;\n    for (auto& tp : ord) {\n  \
    \      int cnt = 0;\n        for (auto& p : tp.second) {\n            p.second\
    \ = cnt++;\n        }\n        g[tp.first].resize(cnt);\n    }\n\n    for (int\
    \ u = 0; u < n1; ++u) {\n        int r = uf.root(u);\n        for (int v : g1[u])\
    \ {\n            g[r][ord[r][u]].emplace_back(ord[r][v]);\n        }\n    }\n\n\
    \    int ans = 0;\n    auto hash = TreeHash(g2).get();\n    for (auto &tp : g)\
    \ {\n        auto h = TreeHash(tp.second).get();\n        ans += h == hash;\n\
    \    }\n\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\
    \n\n#include \"../../../lib/tree/tree_hash.cpp\"\n#include \"../../../lib/structure/union_find.cpp\"\
    \n\nint main() {\n    int n1, m1; cin >> n1 >> m1;\n    vector<vector<int>> g1(n1);\n\
    \    UnionFind uf(n1);\n    REP(i, m1) {\n        int u, v; cin >> u >> v; --u,\
    \ --v;\n        g1[u].emplace_back(v);\n        g1[v].emplace_back(u);\n     \
    \   uf.merge(u, v);\n    }\n    int n2; cin >> n2;\n    vector<vector<int>> g2(n2);\n\
    \    REP(i, n2-1) {\n        int u, v; cin >> u >> v; --u, --v;\n        g2[u].emplace_back(v);\n\
    \        g2[v].emplace_back(u);\n    }\n\n    vector<int> roots;\n    for (int\
    \ i = 0; i < n1; ++i) if (uf.root(i) == i) roots.emplace_back(i);\n\n    map<int,map<int,int>>\
    \ ord;\n    for (int i = 0; i < n1; ++i) {\n        ord[uf.root(i)][i] = -1;\n\
    \    }\n\n    map<int,vector<vector<int>>> g;\n    for (auto& tp : ord) {\n  \
    \      int cnt = 0;\n        for (auto& p : tp.second) {\n            p.second\
    \ = cnt++;\n        }\n        g[tp.first].resize(cnt);\n    }\n\n    for (int\
    \ u = 0; u < n1; ++u) {\n        int r = uf.root(u);\n        for (int v : g1[u])\
    \ {\n            g[r][ord[r][u]].emplace_back(ord[r][v]);\n        }\n    }\n\n\
    \    int ans = 0;\n    auto hash = TreeHash(g2).get();\n    for (auto &tp : g)\
    \ {\n        auto h = TreeHash(tp.second).get();\n        ans += h == hash;\n\
    \    }\n\n    cout << ans << endl;\n}\n"
  dependsOn:
  - lib/tree/tree_hash.cpp
  - lib/template.cpp
  - lib/tree/centroid.cpp
  - lib/structure/union_find.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/tree/tree_hash/tree_hash.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/tree_hash/tree_hash.test.cpp
layout: document
redirect_from:
- /verify/test/tree/tree_hash/tree_hash.test.cpp
- /verify/test/tree/tree_hash/tree_hash.test.cpp.html
title: test/tree/tree_hash/tree_hash.test.cpp
---
