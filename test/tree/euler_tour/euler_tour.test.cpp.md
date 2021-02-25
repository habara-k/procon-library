---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/fenwick_tree.cpp
    title: lib/structure/fenwick_tree.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/euler_tour.cpp
    title: lib/tree/euler_tour.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
  bundledCode: "#line 1 \"test/tree/euler_tour/euler_tour.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\n\n#line\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/tree/euler_tour.cpp\"\n\nstruct EulerTour\
    \ {\n    vector<int> ds, us;\n    vector<vector<int>> g;\n\n    EulerTour(const\
    \ vector<vector<int>>& g) :\n        g(g), ds(g.size()), us(g.size()) {}\n\n \
    \   void dfs(int u, int p, int& idx) {\n        for (int v : g[u]) {\n       \
    \     if (v == p) continue;\n            ds[v] = idx++;\n            dfs(v, u,\
    \ idx);\n            us[v] = idx++;\n        }\n    }\n\n    void build(int root=0)\
    \ {\n        int idx = 1;\n        dfs(root, -1, idx);\n        us[root] = 2 *\
    \ g.size() - 1;\n    }\n};\n#line 2 \"lib/structure/fenwick_tree.cpp\"\n\ntemplate<typename\
    \ T>\nstruct fenwick_tree {\n    vector<T> data;\n    int sz;\n    fenwick_tree(int\
    \ sz) : sz(sz), data(sz+1) {}\n\n    void add(int i, T x) {\n        // a[i] +=\
    \ x;\n        assert(0 <= i and i < sz);\n        for (++i; i <= sz; i += i &\
    \ -i) data[i] += x;\n    }\n\n    T sum(int i) const {\n        // return a[0]\
    \ + ... + a[i-1]\n        assert(0 <= i and i <= sz);\n        T s = 0;\n    \
    \    for (; i > 0; i -= i & -i) s += data[i];\n        return s;\n    }\n\n  \
    \  T sum(int l, int r) const {\n        // return a[l] + ... + a[r-1]\n      \
    \  return sum(r) - sum(l);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ const fenwick_tree& a) {\n        os << \"[\";\n        for (int i = 0; i <\
    \ a.sz; ++i) {\n            if (i) os << \" \";\n            os << a.sum(i, i+1);\n\
    \        }\n        return os << \"]\";\n    }\n};\n#line 5 \"test/tree/euler_tour/euler_tour.test.cpp\"\
    \n\nint main() {\n    int n; cin >> n;\n    vector<vector<int>> G(n);\n    for\
    \ (int i = 0; i < n; ++i) {\n        int k; cin >> k; G[i].resize(k);\n      \
    \  for (int j = 0; j < k; ++j) {\n            cin >> G[i][j];\n        }\n   \
    \ }\n\n    EulerTour tour(G);\n    tour.build(0);\n\n    fenwick_tree<int> fw(2*n);\n\
    \    int q; cin >> q;\n    while (q--) {\n        int c; cin >> c;\n        if\
    \ (c == 1) {\n            int v; cin >> v;\n            cout << fw.sum(0, tour.ds[v]+1)\
    \ << endl;\n        }\n        if (c == 0) {\n            int v, w; cin >> v >>\
    \ w;\n            fw.add(tour.ds[v], w);\n            fw.add(tour.us[v], -w);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include \"../../../lib/tree/euler_tour.cpp\"\n#include \"../../../lib/structure/fenwick_tree.cpp\"\
    \n\nint main() {\n    int n; cin >> n;\n    vector<vector<int>> G(n);\n    for\
    \ (int i = 0; i < n; ++i) {\n        int k; cin >> k; G[i].resize(k);\n      \
    \  for (int j = 0; j < k; ++j) {\n            cin >> G[i][j];\n        }\n   \
    \ }\n\n    EulerTour tour(G);\n    tour.build(0);\n\n    fenwick_tree<int> fw(2*n);\n\
    \    int q; cin >> q;\n    while (q--) {\n        int c; cin >> c;\n        if\
    \ (c == 1) {\n            int v; cin >> v;\n            cout << fw.sum(0, tour.ds[v]+1)\
    \ << endl;\n        }\n        if (c == 0) {\n            int v, w; cin >> v >>\
    \ w;\n            fw.add(tour.ds[v], w);\n            fw.add(tour.us[v], -w);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - lib/tree/euler_tour.cpp
  - lib/template.cpp
  - lib/structure/fenwick_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/tree/euler_tour/euler_tour.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/euler_tour/euler_tour.test.cpp
layout: document
redirect_from:
- /verify/test/tree/euler_tour/euler_tour.test.cpp
- /verify/test/tree/euler_tour/euler_tour.test.cpp.html
title: test/tree/euler_tour/euler_tour.test.cpp
---
