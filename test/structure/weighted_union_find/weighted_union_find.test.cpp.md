---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/weighted_union_find.cpp
    title: lib/structure/weighted_union_find.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
  bundledCode: "#line 1 \"test/structure/weighted_union_find/weighted_union_find.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
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
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/structure/weighted_union_find.cpp\"\n\n\
    template<typename A>\nstruct WeightedUnionFind\n{\n    vector<int> par, sz;\n\
    \    vector<A> data;     // data[x]: diff from root to x\n    WeightedUnionFind(int\
    \ n, A e=0) :\n        par(n), sz(n, 1), data(n, e) {\n        for (int i = 0;\
    \ i < n; ++i) par[i] = i;\n    }\n\n    int root(int x) {\n        if (par[x]\
    \ == x) return x;\n        int r = root(par[x]);\n        data[x] += data[par[x]];\n\
    \        return par[x] = r;\n    }\n\n    A weight(int x) {\n        root(x);\n\
    \        return data[x];\n    }\n\n    A diff(int x, int y) {\n        // diff\
    \ from x to y\n        return data[y] - data[x];\n    }\n\n    void merge(int\
    \ x, int y, A w) {\n        // merge so that \"diff from x to y\" will be w.\n\
    \        w += weight(x); w -= weight(y);\n        x = root(x); y = root(y);\n\
    \        if (x == y) return;\n        if (sz[x] < sz[y]) swap(x, y), w = -w;\n\
    \        par[y] = x;\n        sz[x] += sz[y];\n        sz[y] = 0;\n        data[y]\
    \ = w;\n    }\n\n    bool issame(int x, int y) {\n        return root(x) == root(y);\n\
    \    }\n};\n#line 4 \"test/structure/weighted_union_find/weighted_union_find.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    WeightedUnionFind<int>\
    \ uf(N);\n    while (M--) {\n        int A, B, C, D;\n        cin >> A >> B >>\
    \ C;\n        if (A == 0) {\n            cin >> D;\n            uf.merge(B, C,\
    \ D);\n        } else {\n            if (uf.root(B) == uf.root(C)) {\n       \
    \         cout << uf.diff(B, C) << endl;\n            } else {\n             \
    \   cout << \"?\" << endl;\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n\n#include \"../../../lib/structure/weighted_union_find.cpp\"\n\nint main()\
    \ {\n    int N, M;\n    cin >> N >> M;\n    WeightedUnionFind<int> uf(N);\n  \
    \  while (M--) {\n        int A, B, C, D;\n        cin >> A >> B >> C;\n     \
    \   if (A == 0) {\n            cin >> D;\n            uf.merge(B, C, D);\n   \
    \     } else {\n            if (uf.root(B) == uf.root(C)) {\n                cout\
    \ << uf.diff(B, C) << endl;\n            } else {\n                cout << \"\
    ?\" << endl;\n            }\n        }\n    }\n}\n"
  dependsOn:
  - lib/structure/weighted_union_find.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/weighted_union_find/weighted_union_find.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/weighted_union_find/weighted_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/structure/weighted_union_find/weighted_union_find.test.cpp
- /verify/test/structure/weighted_union_find/weighted_union_find.test.cpp.html
title: test/structure/weighted_union_find/weighted_union_find.test.cpp
---
