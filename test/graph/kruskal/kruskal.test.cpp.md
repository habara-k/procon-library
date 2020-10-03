---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/edge.cpp
    title: lib/graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/edge.cpp
    title: lib/graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.cpp
    title: lib/graph/kruskal.cpp
  - icon: ':heavy_check_mark:'
    path: lib/structure/union_find.cpp
    title: lib/structure/union_find.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/graph/kruskal/kruskal.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\n\n#line 1\
    \ \"lib/graph/edge.cpp\"\n\n\n#line 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// type {{{\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\nusing P = pair<int,int>;\nusing vi = vector<int>;\n\
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
    \ 1e-9;\n// }}}\n\n\n#line 4 \"lib/graph/edge.cpp\"\n\ntemplate<typename T>\n\
    struct edge {\n    int src, to;\n    T cost;\n\n    friend ostream& operator<<(ostream&\
    \ os, const edge& e) {\n        return os << \"(\" << e.src << \"->\" << e.to\
    \ << \":\" << e.cost << \")\";\n    }\n};\n\ntemplate<typename T>\nusing Graph\
    \ = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/structure/union_find.cpp\"\n\n\
    struct UnionFind\n{\n    const int n;\n    vector<int> par, sz;\n    UnionFind(int\
    \ n) : n(n), par(n), sz(n, 1) {\n        for (int i = 0; i < n; ++i) par[i] =\
    \ i;\n    }\n\n    int root(int x) {\n        if (par[x] == x) return x;\n   \
    \     return par[x] = root(par[x]);\n    }\n\n    void merge(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if (x == y) return;\n   \
    \     if (sz[x] < sz[y]) swap(x, y);\n        par[y] = x;\n        sz[x] += sz[y];\n\
    \        sz[y] = 0;\n    }\n\n    bool issame(int x, int y) {\n        return\
    \ root(x) == root(y);\n    }\n\n    int size(int x) {\n        return sz[root(x)];\n\
    \    }\n\n    friend ostream& operator<<(ostream& os, UnionFind& uf) {\n     \
    \   os << \"[\";\n        for (int i = 0; i < uf.n; ++i) {\n            if (i\
    \ > 0) os << \" \";\n            os << uf.root(i);\n        }\n        return\
    \ os << \"]\" << endl;\n    }\n};\n#line 4 \"lib/graph/kruskal.cpp\"\n\ntemplate<typename\
    \ T>\nT kruskal(const vector<edge<T>> &es, int V) {\n\n    UnionFind uf(V);\n\
    \    T ret = 0;\n\n    vector<int> ord(es.size());\n    iota(ord.begin(), ord.end(),\
    \ 0);\n    sort(ord.begin(), ord.end(), [&](int i,int j){\n            return\
    \ es[i].cost < es[j].cost;\n            });\n\n    for (auto i : ord) {\n    \
    \    auto &e = es[i];\n        if (!uf.issame(e.src, e.to)) {\n            ret\
    \ += e.cost;\n            uf.merge(e.src, e.to);\n        }\n    }\n\n    return\
    \ ret;\n}\n#line 5 \"test/graph/kruskal/kruskal.test.cpp\"\n\nint main() {\n \
    \   int V, E;\n    cin >> V >> E;\n    vector<edge<int>> edges;\n    for (int\
    \ i = 0; i < E; ++i) {\n        int a, b, c;\n        cin >> a >> b >> c;\n  \
    \      edges.push_back({a, b, c});\n    }\n    cout << kruskal(edges, V) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include \"../../../lib/graph/edge.cpp\"\n#include \"../../../lib/graph/kruskal.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<edge<int>> edges;\n\
    \    for (int i = 0; i < E; ++i) {\n        int a, b, c;\n        cin >> a >>\
    \ b >> c;\n        edges.push_back({a, b, c});\n    }\n    cout << kruskal(edges,\
    \ V) << endl;\n}\n"
  dependsOn:
  - lib/graph/edge.cpp
  - lib/template.cpp
  - lib/graph/kruskal.cpp
  - lib/graph/edge.cpp
  - lib/structure/union_find.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/kruskal/kruskal.test.cpp
  requiredBy: []
  timestamp: '2020-06-26 12:56:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/kruskal/kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/graph/kruskal/kruskal.test.cpp
- /verify/test/graph/kruskal/kruskal.test.cpp.html
title: test/graph/kruskal/kruskal.test.cpp
---
